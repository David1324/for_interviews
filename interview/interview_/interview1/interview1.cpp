// this program inputs an expression in postfix then evaluates that expression
// by david 

#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>

using namespace std;

//int main()
//{
//	cout << "hello there!" << endl;
//	getchar();
//
//	return 0;
//
//}

void EraseStack(stack<double> stack_numbers);	// empties out the stack
double GetNext(string expression, int &pos);	// returns next number in stack

int main()
{
	string expression;
	stack<double> stack_numbers;
	int pos = 0;	// keeps track of position in expression
	double number, num1, num2;
	bool invalid = false;

	// priming input
	cout << "Enter Expression: ";
	//getline(cin, expression);
	expression = "2+7";

	while (expression != "quit")	// controls each session
	{
		EraseStack(stack_numbers);
		pos = 0;
		invalid = false;

		while (pos <= expression.length() - 1)	// controls each expression
		{
			if (isdigit(expression[pos]))	// is an operand
			{
				number = GetNext(expression, pos);
				stack_numbers.push(number);
			}
			else
			{
				if (stack_numbers.empty())	// checks for invalid expression 
				{
					invalid = true;
					pos = expression.length();
				}
				else
				{
					num1 = stack_numbers.top();
					stack_numbers.pop();

					num2 = stack_numbers.top();
					stack_numbers.pop();

					switch (expression[pos])
					{
					case '+':	// addition
						number = num1 + num2;
						break;
					case '-':	// subtraction
						number = num2 - num1;
						break;
					case '*':	// multiplication
						number = num1 * num2;
						break;
					case '/':	// division
						number = num2 / num1;
						break;
					case '^':	// exponents
						number = pow(num2, num1);
						break;
					}
					stack_numbers.push(number);
					pos += 2;
				}
			}
		}

		if (!invalid)
		{
			cout << expression << " = " << number << endl;
			getline(cin, expression);
		}
		else
			cout << "Invalid Expression" << endl;
	}

	return 0;
}


// returns next number in stack
double GetNext(string expression, int &pos)
{
	string number;
	number = expression[pos];
	pos++;

	while (isdigit(expression[pos]))
	{
		number += expression[pos];
		pos++;
	}

	//pos++;
	double number2 = atoi(number.c_str());

	return number2;
}


// clean out the stack
void EraseStack(stack<double> stack_numbers)
{
	while (stack_numbers.empty() == false)
		stack_numbers.pop();
}