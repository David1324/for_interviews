#include <iostream>

using namespace std;

bool my_strcmp(char* str1, char* str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
		i++;
	}
	bool is_same = str1[i] == str2[i]; //to check if both strings are in same length
	return is_same;
}

int main()
{
	char str1[] = "abc";
	char str2[] = "abcd";
	bool is_same = my_strcmp(str1, str2);
	if (is_same)
	{
		cout << "'"<< str1 << "' and '" << str2 << "' are the same." << endl;
	}
	else
	{
		cout << "'" << str1 << "' and '" << str2 << "' are NOT the same." << endl;
	}
	getchar();
	return 0;
}