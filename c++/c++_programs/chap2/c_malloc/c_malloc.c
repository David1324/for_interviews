#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
	int addresses[N] = { 0 };
	int i;
	for (i = 0; i < N; i++)
	{
		void* addr = malloc(1024);
		int* int_addr_ptr = (int*)addr;
		int int_addr = (int)int_addr_ptr;
		printf("address[%d]:\t0x%X\n", i,int_addr);
		
		addresses[i] = int_addr;
	}

	printf("\n\n");
	for (i = 1; i < N; i++)
	{
		int current_diff = addresses[i] - addresses[i - 1];
		printf("address[%d]-address[%d]=0x%X=%d\n", i, i - 1, current_diff, current_diff);
	}
	getchar();
	return 0;
}