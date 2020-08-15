#include <stdio.h>

#define ARR_SIZE 8

bool find_in_sorted_array(int num, int* arr, int arr_size)
{
	int first = 0;
	int last = arr_size-1;
	int middle;

	while (last - first > 1)
	{
		int temp;
		middle = (first + last) / 2;
		temp = arr[middle];
		if (temp == num) return true;
		if (temp < num)
		{
			first = middle;
		}
		else
		{
			last = middle;
		}
	}
	return false;
}

void swap_without_using_more_memory(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main()
{
	int arr[ARR_SIZE] = { 1, 5, 8, 20, 30, 42, 53, 85 };
	int num = 600;
	bool is_exist = find_in_sorted_array(num, arr, ARR_SIZE);

	if (is_exist)
		printf("num %d exists in array\n", num);
	else
		printf("num %d doest NOT exist in array\n", num);

	

	//////////////////////////////////////////////////////////////////////////////////////

	int a = 50;
	int b = 13;
	printf("before swap:\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	swap_without_using_more_memory(&a, &b);
	printf("after swap:\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);




	getchar();

}