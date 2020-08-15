#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

enum Color { red, yellow, green, last };
const int num_of_colors = 5;

void print_array(Color* arr, int arr_length)
{
	for (int i = 0; i < num_of_colors; i++)
	{
		/*std::cout << "arr[" << i << "]=" << arr[i] << ", ";*/
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

void my_swap(Color* color1, Color* color2)
{
	Color temp = *color1;
	*color1 = *color2;
	*color2 = temp;
}

void move_color_to_start(Color color, Color* arr, Color* &ptr_start)
{
	//passing ptr_start BY REFERENCE since it should be updated from outside the function
	Color* ptr_end = &(arr[num_of_colors - 1]);
	while (ptr_end>ptr_start)
	{
		while (*ptr_start == color)
		{
			ptr_start++;
		}
		while (*ptr_end != color)
		{
			ptr_end--;
		}
		if (ptr_end > ptr_start)
		{
			//std::swap(*ptr_start, *ptr_end);
			my_swap(ptr_start, ptr_end);
		}
	}
}

int main()
{
	
	/* initialize random seed: */
	srand(time(NULL));

	Color arr[num_of_colors];
	for (int i = 0; i < num_of_colors; i++)
	{
		arr[i] = (Color) (rand() % last);
	}
	print_array(arr, num_of_colors);

	Color* ptr_start = &arr[0];
	move_color_to_start(red, arr, ptr_start);

	print_array(arr, num_of_colors);

	//ptr_start already in the right location (after the last red)
	move_color_to_start(yellow, arr, ptr_start);
	print_array(arr, num_of_colors);

	getchar();
}