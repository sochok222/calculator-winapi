

#include<cctype>
#include<iostream>
#include<stack>
#include<string>

class Calculator
{
public:
	static std::pair<long double, std::string> calculate(std::string str)
	{
		std::stack<double> stk;
		std::string buffer;
		char lastOperator = '+';
		long double num = 0;

		while (!str.empty())
		{
			char el = str[0];
			str.erase(0, 1);

			if (std::isdigit(el) || (el == '-' && (buffer.empty() || buffer == "-")))
			{
				buffer += el;	
			}
			else if (!std::isdigit(el))
			{
				if (el == '(' && buffer == "-")
				{
					auto [newValue, newStr] = calculate(str);
					stk.push(-newValue);
					str = newStr;
					buffer.clear();
				}
				else if (el == '(')
				{
					auto [newValue, newStr] = calculate(str);
					if (lastOperator == '*')
					{
						long double prevValue = stk.top();
						stk.pop();
						stk.push(prevValue * newValue);
					}
					else if (lastOperator == '/')
					{
						long double prevValue = stk.top();
						stk.pop();
						stk.push(prevValue / newValue);
					}
					else {
						stk.push(newValue);
					}
					str = newStr;
					buffer.clear();
				}
				else
				{
					if (!buffer.empty())
					{
						if (lastOperator == '+')
						{
							stk.push(std::stold(buffer));
						}
						else if (lastOperator == '-')
						{
							stk.push(-std::stold(buffer));
						}
						else if (lastOperator == '*')
						{
							long double top = stk.top();
							stk.pop();
							long double b = std::stold(buffer);
							long double result = b * top;
							stk.push(result);
						}
						else if (lastOperator == '/')
						{
							long double top = stk.top();
							stk.pop();
							long double b = std::stold(buffer);
							long double result = b / top;
							stk.push(result);
						}
						buffer.clear();
					}
					lastOperator = el;
				}
				if (el == ')')
				{
					break;
				}
			}
		}
		if (!buffer.empty())
		{
			if (lastOperator == '+')
			{
				stk.push(std::stold(buffer));
			}
			else if (lastOperator == '-')
			{
				stk.push(-std::stod(buffer));
			}
			else if (lastOperator == '*')
			{
				long double top = stk.top();
				stk.pop();
				stk.push(std::stold(buffer) * top);
			}
			else if (lastOperator == '/')
			{
				long double top = stk.top();
				stk.pop();
				stk.push(top / std::stold(buffer));
			}
			buffer.clear();
		}
		long double res = 0;
		while (!stk.empty())
		{
			res += stk.top();
			stk.pop();
		}

		return { res, str };
	}
};

	