#include <stdio.h>

int num_of_1s[256];
int first1[256];
int second1[256];
int third1[256];

void calculate_num_of_1s(int* num_of_1s);
int find_third1fast(int reg);
int find_occurance_location(int reg, int num_of_occurances);
int count_1s_bits(int reg);
void calculate_occurace(int* occurance, int num_of_occurances);


void calculate_num_of_1s(int* num_of_1s)
{
	for (int i = 0; i < 256; i++)
	{
		int current_num_of_1s = count_1s_bits(i);
		num_of_1s[i] = current_num_of_1s;
	}
}

void calculate_occurace(int* occurance, int num_of_occurances)
{
	for (int i = 0; i < 256; i++)
	{
		occurance[i] = find_occurance_location(i, num_of_occurances);
	}
}

int find_third1fast(int reg)
{
	int count = 0;
	int* locations[4] = { NULL, first1, second1, third1 };
	for (int n = 0; n < 4; n++)
	{
		int eight_n = 8 * n;
		int shiftet_reg = reg >> eight_n;
		char unit = (char)shiftet_reg;
		int num_of_1s_unit = num_of_1s[unit];
		int temp = count + num_of_1s_unit;
		if (temp < 3)
		{
			count += num_of_1s_unit;
		}
		else
		{
			int temp1 = locations[3 - count][unit];
			return 8 * n + temp1;
		}
	}
	return -1;
}

int find_occurance_location(int reg, int num_of_occurances)
{
	int count = 0;
	int num_of_bytes = sizeof(int);
	int num_of_bits = 8 * num_of_bytes;
	for (int i = 0; i < num_of_bits; i++)
	{
		int shifted_reg = reg >> i;
		int last_bit = shifted_reg & 1;
		count = count + last_bit;
		if (count == num_of_occurances)
		{
			return i;
		}
	}
	return -1;
}

int count_1s_bits(int reg)
{
	int count = 0;
	int num_of_bytes = sizeof(int);
	int num_of_bits = 8 * num_of_bytes;
	for (int i = 0; i < num_of_bits; i++)
	{
		int shifted_reg = reg >> i;
		int last_bit = shifted_reg & 1;
		count = count + last_bit;
	}
	return count;
}

int main()
{
	int reg = 0x00060408;
	calculate_num_of_1s(num_of_1s);
	calculate_occurace(first1, 1);
	calculate_occurace(second1, 2);
	calculate_occurace(third1, 3);

	int location = find_occurance_location(reg, 3);
	int location_fast = find_third1fast(reg);

	printf("location = %d\n", location);
	printf("location_fast = %d\n\n", location_fast);


	int number_of_1s = count_1s_bits(reg);



	printf("There are %d 1s in the number 0x%X", number_of_1s, reg);
	getchar();
}