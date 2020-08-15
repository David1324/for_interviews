#include < iostream >
#include < stdio.h >
using namespace std;
int main()
{
	int david[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int array[] = { 0, 1, 1, 0, 1, 1, 0, 0, 1, 0 };
	//(0,1), (0,3), (0,7), (0,9)
	//(2,3), (2,7), (2,9)
	int count_zero = 0, count_one = 0;

	int len = sizeof(array) / sizeof(int);
	for (int i = 0; i < len; i++)
	{
		count_zero = 0;
		count_one = 0;

		if (array[i] == 0)
			count_zero++;
		else
			count_one++;
		for (int j = i + 1; j < len+1; j++)
		{

			if (count_zero == count_one)
			{
				cout << "( " << i << "," << j - 1 << " )";
			}

			if (j == len) break;
			if (array[j] == 0)
				count_zero++;
			else
				count_one++;
		}
		cout << endl;
	}
	getchar();
	return 0;
}