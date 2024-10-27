#include <windows.h>
#include<iostream> 
#include <string>
#include <cstdio>
#include "CalculatorLogic.cpp"
#define ID_BUTTON0 1000
#define ID_BUTTON1 1001
#define ID_BUTTON2 1002
#define ID_BUTTON3 1003
#define ID_BUTTON4 1004
#define ID_BUTTON5 1005
#define ID_BUTTON6 1006
#define ID_BUTTON7 1007
#define ID_BUTTON8 1008
#define ID_BUTTON9 1009
#define ID_PLUS 1010
#define ID_MINUS 1011   
#define ID_CLEAR 1012
#define ID_EQUAL 1013
#define ID_ERASE 1014
#define ID_MUL 1015
#define ID_DIVIDE 1016
#define ID_LEFTBRACKET 1017
#define ID_RIGHTBRACKET 1018

int a = 0;
int b = 0;
std::string oper;

bool HasText(HWND hwndEdit) {
   int length = (int)SendMessage(hwndEdit, WM_GETTEXTLENGTH, 0, 0);

   return length;
}

int ExtractNumber(const char* input)
{
   std::string nStr;

   for (int i = 0; i < strlen(input); i++)
   {
      if (std::isdigit(static_cast<unsigned char>(input[i])))
      {
         nStr += input[i];
      }
   }
   return stoi(nStr);
}

const char g_szClassName[] = "myWindowClass";
HWND hEdit;
HWND hTemple;
HFONT hFontm, hFonts;
static WNDPROC oldEditProc;

LPSTR IntToLPSTR(int value) {
   std::string str = std::to_string(value);
   LPSTR lpstr = new char[str.size() + 1];
   std::copy(str.begin(), str.end(), lpstr);
   lpstr[str.size()] = '\0';
   return lpstr;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
   switch (msg)
   {
      break;
   case WM_COMMAND:
   {
      int wmId = LOWORD(wParam);
      switch (wmId)
      {
      case ID_BUTTON0:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '0';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_BUTTON1:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '1';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_BUTTON2:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '2';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_BUTTON3:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '3';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_BUTTON4:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '4';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_BUTTON5:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '5';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_BUTTON6:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '6';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_BUTTON7:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '7';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_BUTTON8:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '8';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_BUTTON9:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '9';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_ERASE:
      {
         try
         {
            char toErase[256];
            GetWindowText(hEdit, toErase, 256);
            toErase[strlen(toErase) - 1] = '\0';
            SetWindowText(hEdit, toErase);
         }
         catch (_exception& e)
         {
            break;
         }
      }
      break;
      case ID_EQUAL:
      {
         if (HasText(hEdit) > 0 || HasText(hTemple) > 0)
         { 
            try
            {
               char toCalculate[256];
               std::string oldStr;
               std::string newStr;
               std::string strResult;
               GetWindowText(hEdit, toCalculate, 256);
               oldStr = toCalculate;

               long double intResult = Calculator::calculate(oldStr).first;

               long double intPart;
               long double fracPart = std::modf(intResult, &intPart);

               if (fracPart == 0.0)
               {
                  strResult = std::to_string(static_cast<long long>(intResult));
               }
               else
               {
                  strResult = std::to_string(intResult);
               }
               
               
               LPCSTR toDisplayHTEMPLE = (oldStr.append("=")).c_str();

               SetWindowText(hEdit, strResult.c_str());
               SetWindowText(hTemple, toDisplayHTEMPLE);
            }
            catch (const std::exception& e)
            {
               MessageBox(NULL, "Calculation Error!", "Error!",
                  MB_ICONEXCLAMATION | MB_OK);
               SetWindowText(hEdit, "");
               SetWindowText(hTemple, "");
            }
         }
      }
      break;
      case ID_CLEAR:
      {
         try
         {
            SetWindowText(hTemple, "");
            SetWindowText(hEdit, "");
         }
         catch (std::exception& e)
         {
            break;
         }
      }
      break;
      case ID_PLUS:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '+';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_MINUS:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '-';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_MUL:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '*';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_DIVIDE:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '/';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_LEFTBRACKET:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = '(';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      break;
      case ID_RIGHTBRACKET:
      {
         char currStr[256];
         GetWindowText(hEdit, currStr, 256);

         size_t len = strlen(currStr);
         currStr[len] = ')';
         currStr[len + 1] = '\0';

         SetWindowText(hEdit, currStr);
      }
      }
   }
   break;

   case WM_CLOSE:
   {
      DestroyWindow(hwnd);
      break;
   }
   case WM_DESTROY:
   {
      PostQuitMessage(0);
      DestroyCaret();
      break;
   }
   default:
      return DefWindowProc(hwnd, msg, wParam, lParam);
   }
   return 0;
}

HWND CreateMainWindow(HINSTANCE hInstance)
{
   return CreateWindowEx(
      WS_EX_CLIENTEDGE,
      g_szClassName,
      "The title of my window",
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, 340, 540,
      NULL, NULL, hInstance, NULL);
}

HWND CreateSomeButton(HWND hwnd, const char* text, int x, int y, HMENU ID)
{
   return CreateWindow(
      "BUTTON",  // Predefined class; Unicode assumed 
      text,      // Button text 
      WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,  // Styles 
      x,         // x position 
      y,         // y position 
      75,        // Button width
      45,        // Button height
      hwnd,     // Parent window
      (HMENU)ID,       // button id.
      (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
      NULL);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
   LPSTR lpCmdLine, int nCmdShow)
{


   WNDCLASSEX wc;
   HWND hwnd;
   MSG Msg;

   //Step 1: Registering the Window Class
   wc.cbSize = sizeof(WNDCLASSEX);
   wc.style = 0;
   wc.lpfnWndProc = WndProc;
   wc.cbClsExtra = 0;
   wc.cbWndExtra = 0;
   wc.hInstance = hInstance;
   wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
   wc.hCursor = LoadCursor(NULL, IDC_ARROW);
   wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
   wc.lpszMenuName = NULL;
   wc.lpszClassName = g_szClassName;
   wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

   if (!RegisterClassEx(&wc))
   {
      MessageBox(NULL, "Window Registration Failed!", "Error!",
         MB_ICONEXCLAMATION | MB_OK);
      return 0;
   }


   // Step 2: Creating the Window
   hwnd = CreateMainWindow(hInstance);
   CreateSomeButton(hwnd, "(", 5, 180, (HMENU)ID_LEFTBRACKET);
   CreateSomeButton(hwnd, ")", 83, 180, (HMENU)ID_RIGHTBRACKET);
   CreateSomeButton(hwnd, "C", 161, 180, (HMENU)ID_CLEAR);
   CreateSomeButton(hwnd, "erase", 239, 180, (HMENU)ID_ERASE);
   CreateSomeButton(hwnd, "1/x", 5, 232, (HMENU)ID_BUTTON0);
   CreateSomeButton(hwnd, "x²", 83, 232, (HMENU)ID_BUTTON0);
   CreateSomeButton(hwnd, "none", 161, 232, (HMENU)ID_BUTTON0);
   CreateSomeButton(hwnd, "/", 239, 232, (HMENU)ID_DIVIDE);
   CreateSomeButton(hwnd, "7", 5, 284, (HMENU)ID_BUTTON7);
   CreateSomeButton(hwnd, "8", 83, 284, (HMENU)ID_BUTTON8);
   CreateSomeButton(hwnd, "9", 161, 284, (HMENU)ID_BUTTON9);
   CreateSomeButton(hwnd, "*", 239, 284, (HMENU)ID_MUL);
   CreateSomeButton(hwnd, "4", 5, 336, (HMENU)ID_BUTTON4);
   CreateSomeButton(hwnd, "5", 83, 336, (HMENU)ID_BUTTON5);
   CreateSomeButton(hwnd, "6", 161, 336, (HMENU)ID_BUTTON6);
   CreateSomeButton(hwnd, "-", 239, 336, (HMENU)ID_MINUS);
   CreateSomeButton(hwnd, "1", 5, 388, (HMENU)ID_BUTTON1);
   CreateSomeButton(hwnd, "2", 83, 388, (HMENU)ID_BUTTON2);
   CreateSomeButton(hwnd, "3", 161, 388, (HMENU)ID_BUTTON3);
   CreateSomeButton(hwnd, "+", 239, 388, (HMENU)ID_PLUS);
   CreateSomeButton(hwnd, "=/-", 5, 440, (HMENU)ID_BUTTON0);
   CreateSomeButton(hwnd, "0", 83, 440, (HMENU)ID_BUTTON0);
   CreateSomeButton(hwnd, ",", 161, 440, (HMENU)ID_BUTTON0);
   CreateSomeButton(hwnd, "=", 239, 440, (HMENU)ID_EQUAL);

   hTemple = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_EX_LAYERED | SS_RIGHT | ES_AUTOHSCROLL | ES_READONLY | WS_DISABLED, 0, 35, 320, 30, hwnd, (HMENU)2, hInstance, 0);

   hEdit = CreateWindowEx(
      0, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_EX_LAYERED | SS_RIGHT | ES_AUTOHSCROLL | ES_READONLY | WS_DISABLED,
      0, 65, 320, 50,
      hwnd, (HMENU)1, hInstance, 0);

   hFontm = CreateFont(
      45,                        // Висота шрифту
      0,                         // Ширина шрифту (0 = автоматична)
      0,                         // Кут нахилу (по горизонталі)
      0,                         // Кут нахилу (по вертикалі)
      FW_NORMAL,                 // Товщина шрифту
      FALSE,                     // Курсив
      FALSE,                     // Підкреслення
      FALSE,                     // Закреслення
      ANSI_CHARSET,              // Набір символів
      OUT_DEFAULT_PRECIS,        // Точність виводу
      CLIP_DEFAULT_PRECIS,       // Точність обрізки
      DEFAULT_QUALITY,           // Якість шрифту
      DEFAULT_PITCH | FF_SWISS,  // Тип шрифту
      "Arial"                    // Ім'я шрифту
   );
   hFonts = CreateFont(
      30,                        // Висота шрифту
      0,                         // Ширина шрифту (0 = автоматична)
      0,                         // Кут нахилу (по горизонталі)
      0,                         // Кут нахилу (по вертикалі)
      FW_NORMAL,                 // Товщина шрифту
      FALSE,                     // Курсив
      FALSE,                     // Підкреслення
      FALSE,                     // Закреслення
      ANSI_CHARSET,              // Набір символів
      OUT_DEFAULT_PRECIS,        // Точність виводу
      CLIP_DEFAULT_PRECIS,       // Точність обрізки
      DEFAULT_QUALITY,           // Якість шрифту
      DEFAULT_PITCH | FF_SWISS,  // Тип шрифту
      "Arial"                    // Ім'я шрифту
   );

   SendMessage(hEdit, WM_SETFONT, (WPARAM)hFontm, TRUE);
   SendMessage(hTemple, WM_SETFONT, (WPARAM)hFonts, TRUE);


   if (hwnd == NULL)
   {
      MessageBox(NULL, "Window Creation Failed!", "Error!",
         MB_ICONEXCLAMATION | MB_OK);
      return 0;
   }

   ShowWindow(hwnd, nCmdShow);
   UpdateWindow(hwnd);

   // Step 3: The Message Loop
   while (GetMessage(&Msg, NULL, 0, 0) > 0)
   {
      TranslateMessage(&Msg);
      DispatchMessage(&Msg);
   }
   return Msg.wParam;
}