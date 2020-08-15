#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int reversDigits(int num)
{
	int rev_num = 0;
	while (num > 0)
	{
		int modulo_10 = num % 10;
		rev_num = rev_num * 10 + modulo_10;
		num = num / 10;
	}
	return rev_num;
}

int n_tu(int number, int count)
{
	int result = 1;
	while (count-- > 0)
		result *= number;

	return result;
}

/*** Convert float to string ***/
void float_to_string(float f, char float_str[])
{
	long long int length, length2, i, number, position, sign;
	float number2;

	sign = -1;   // -1 == positive number
	if (f < 0)
	{
		sign = '-';
		f *= -1;
	}

	number2 = f;
	number = (long long int)f;
	length = 0;  // Size of decimal part
	length2 = 0; // Size of tenth

				 /* Calculate length2 tenth part */
	while ((number2 - (float)number) != 0.0 && !((number2 - (float)number) < 0.0))
	{
		number2 = f * (n_tu(10.0, length2 + 1));
		number = (long long int)number2;

		length2++;
	}

	/* Calculate length decimal part */
	for (length = (f > 1) ? 0 : 1; f > 1; length++)
		f /= 10;

	position = length;
	length = length + 1 + length2;
	number = (long long int)number2;
	if (sign == '-')
	{
		length++;
		position++;
	}

	for (i = length; i >= 0; i--)
	{
		if (i == (length))
			float_str[i] = '\0';
		else if (i == (position))
			float_str[i] = '.';
		else if (sign == '-' && i == 0)
			float_str[i] = '-';
		else
		{
			float_str[i] = (number % 10) + '0';
			number /= 10;
		}
	}
}

///*** Convert float to string ***/
//void float_to_string(float float_num, char float_str[])
//{	
//	float new_float_num = float_num;
//	long trunced_num = (long)new_float_num;
//	float diff = new_float_num - trunced_num;
//	double eps = 10 ^ -2;
//	while (diff > eps)
//	{
//		new_float_num = new_float_num * 10.0f;
//		trunced_num = (long)new_float_num;
//		diff = new_float_num - trunced_num;
//	}
//}


void printm(char *str, ...)
{
	int num;
	char* my_string;
	float float_num;
	char token;
	va_list params;
	va_start(params, str);

	//num = va_arg(params, int);
	//my_string = va_arg(params, char *);
	//float_num = va_arg(params, double);

	char current_char = *str;
	while (current_char != '\0')
	{
		if (current_char == '%')
		{
			token = *(++str);
			switch (token)
			{
			case 'd':
				num = va_arg(params, int);
				int reversed_num = reversDigits(num);
				while (reversed_num % 10 > 0)
				{
					int last_digit = reversed_num % 10;
					char last_digit_char = last_digit + '0';					
					putchar(last_digit_char);
					reversed_num = reversed_num / 10;
				}
				break;

			case '%':
				putchar(token);
				break;

			case 's':
				my_string = va_arg(params, char *);
				while (*my_string != '\0')
				{
					putchar(*my_string);
					my_string++;
				}					
				break;

			case 'f':
				float_num = va_arg(params, double);

				char float_str[40] = "blabla";
				float_to_string(float_num, float_str);
				int index = 0;
				while (float_str[index] != '\0')
				{
					putchar(float_str[index]);
					index++;
				}
				//puts(float_str);
				//printf("%f", float_num);
				break;
			}
		}
		else
			putchar(current_char);
		str++;
		current_char = *str;
	}
}
int main()
{
	int i = 73;
	float j = 27.582f;
	char *str = "david";

	printm("There are %d people together with %s. on average %f people in each room\n", i, str, j);
	getchar();
	return 0;
}
