#include <iostream>

#define TYPE int

using std::cout;
using std::endl;


template <class T>
T calc_revesed_num(T num)
{
	int num_of_bytes = sizeof(num);
	int num_of_bits = 8 * num_of_bytes;
	T reversed_num = 0;
	for (int i = 0; i < num_of_bits; i++)
	{
		T shifted_num = num >> i;
		T current_bit = shifted_num & 1;
		T current_bit_multiplied = current_bit << (num_of_bits - i - 1);
		reversed_num |= current_bit_multiplied;
	}
	return reversed_num;
}

template <class T>
void print_num(T num)
{
	//int num_of_bytes = sizeof(T);
	//int num_of_bits = 8 * num_of_bytes;
	//T temp = 1 << num_of_bits;
	T mask = -1;
	T masked_num = num & mask;
	printf("0x%X\n", masked_num);
}


int main()
{
	TYPE num = 0x00000001;
	TYPE reversed_num = calc_revesed_num<TYPE>(num);
	printf("Original num = ");
	print_num<TYPE>(num);
	printf("Reversed num = ");
	print_num<TYPE>(reversed_num);
	getchar();
	return 0;
}