#include <iostream>

using std::cout;
using std::endl;

int calc_update_bits1(int n, int m, int i, int j)
{
	int max = ~0; //all ones

	//1's through position j, then 0's
	int left = max - ((i << j) - 1);

	//1's after position i
	int right = ((1 << i) - 1);

	//1's, with 0s between i and j
	int mask = left | right;

	//clear i through j, then put m in there
	int val = (n & mask) | (m << i);

	return val;
}




int calc_update_bits2(int n, int m, int i, int j)
{
	int all_ones = 0xFFFFFFFF;
	int temp = 1 << (j - i + 1);
	int ones = temp - 1;
	int not_of_mask = ones << i;
	int mask = ~not_of_mask;

	int n_zeros_i_j = n & mask;
	int mask2 = m << i;
	int val = n_zeros_i_j | mask2;
	return val;
}

int main()
{
	int N = 0x0400;
	int M = 0x0015;
	int i = 2;
	int j = 6;

	int updated_bits1 = calc_update_bits1(N, M, i, j);
	int updated_bits2 = calc_update_bits2(N, M, i, j);

	printf("N = 0x%X\n", N);
	printf("M = 0x%X\n", M);
	printf("i = 0x%X\n", i);
	printf("j = 0x%X\n", j);
	printf("updated_bits1 = 0x%X\n", updated_bits1);
	printf("updated_bits2 = 0x%X\n", updated_bits2);

	getchar();
	return 0;
	

}