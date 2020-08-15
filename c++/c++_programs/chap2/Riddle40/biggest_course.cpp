
#include <iostream>
#define R 4
#define C 4

#ifndef max
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#ifndef min
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

using std::cout;
using std::endl;

int* build_tavlat_ezer(int* arr)
{
	static int new_arr[R*C] = { 0 };
	for (int i = 0; i < C; i++)
	{
		new_arr[i] = arr[i];
	}
	for (int i = 1; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int current_index = i * C + j;
			if (j == 0)
			{				
				int val1 = new_arr[(i - 1)*C + j];
				int val2 = new_arr[(i - 1)*C + j+1];
				new_arr[current_index] = max(val1, val2)+arr[current_index];
			}
			else if (j == C-1)
			{
				int val1 = new_arr[(i - 1)*C + j - 1];
				int val2 = new_arr[(i - 1)*C + j];
				new_arr[current_index] = max(val1, val2) + arr[current_index];
			}
			else
			{
				int val1 = new_arr[(i - 1)*C + j - 1];
				int val2 = new_arr[(i - 1)*C + j];
				int val3 = new_arr[(i - 1)*C + j + 1];
				int current_max = max(val1, val2);
				new_arr[current_index] = max(current_max, val3) + arr[current_index];
			}
		}
	}
	return new_arr;
}

void print_array(int* arr)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << arr[i*C + j] << ", ";
		}
		cout << endl;
	}
	cout << "\n\n";
}

int main()
{
	//int arr[N][N] = { {4,12,2,7},{6,1,10,9},{8,7,10,4},{6,8,5,11} };
	int arr[R*C] = {4,12,2,7,   6,1,10,9,   38,7,10,4,   6,8,5,11 };
	int* new_arr = build_tavlat_ezer(arr);
	print_array(arr);
	print_array(new_arr);
	getchar();
}