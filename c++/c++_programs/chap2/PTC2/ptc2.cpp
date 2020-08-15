#include <stdio.h>

void add1(int a)
{
	int a_addr = (int)&a;
	printf("a address inside function: 0x%X\n", a_addr);
	a += 5;
}

void add2(int* a)
{
	*a += 5;
}

void add3(int& a)
{
	int a_addr = (int)&a;
	printf("a address inside function: 0x%X\n", a_addr);
	a += 5;
}

int main()
{
	int a = 5;
	int a_addr = (int)&a;
	printf("a address in main: 0x%X\n", a_addr);
	add1(a);
	//add2(&a);
	//add3(a);
	printf("%d", a);
	getchar();
	return 0;
}

