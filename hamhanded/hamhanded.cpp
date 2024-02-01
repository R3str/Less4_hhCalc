// hamhanded.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "hamhanded.h"
#include <cctype>

// TODO: This is an example of a library function
int hhAdd(int a, int b)
{
	return a + b;
}

int hhCalc(const char* str)
{
	char c;

	int a = 0;
	int b = NULL;
	char op = NULL;

	bool changeNumber = false;
	bool isSignOp = false;

	// hexadecimal to decimal and get sign operation
	while (0 != (c = *str++))
	{
		if (!isdigit(c))
		{
			if (isSignOp) {
				return -1;
			}

			if (c == '+' || c == '-' || c == '*' || c == '/') {
				if (b != NULL)
				{
					switch (op) {
					case '+':
						a += b;
						break;
					case '-':
						a -= b;
						break;
					case '*':
						a *= b;
						break;
					case '/':
						a /= b;
						break;
					}
					b = NULL;
				}
				op = c;

				changeNumber = true;
				isSignOp = true;
				continue;
			}
			else {
				isSignOp = true;
				continue;
			}
		}

		if (!changeNumber) {
			a = a * 10 + (c - '0');
			isSignOp = false;
		}
		else {
			b = b * 10 + (c - '0');
			isSignOp = false;
		}
	}

	switch (op) {
	case '+':
		a += b;
		break;
	case '-':
		a -= b;
		break;
	case '*':
		a *= b;
		break;
	case '/':
		a /= b;
		break;
	}

	return a;
}
