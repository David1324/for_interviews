#include <string>
#include <iostream>

int my_strcmp(char* str1, char* str2)
{
	while (*str1!='\0' && *str2!='\0')
	{
		if (*str1 < *str2)
		{
			return -1;
		}
		if (*str1 > *str2)
		{
			return 1;
		}
		str1++;
		str2++;
	}
	if (*str1 < *str2)
	{
		return -1;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
}

int main()
{
	char str1[] = "cellod";
	char str2[] = "celloz";

	int ans1 = strcmp(str1, str2);
	int my_ans = my_strcmp(str1, str2);

	printf("ans1 = %d\n", ans1);
	printf("my_ans = %d\n", my_ans);
	
	getchar();
	return 0;
}