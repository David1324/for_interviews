#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h> //size_t

#define TYPE int

//#define SWAP_MACRO(a,b,t) {t temp = *a; *a = *b; *b = temp;}
#define SWAP_MACRO(a,b,t) {t temp = a; a = b; b = temp;}

void swap1(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_void(void* a, void* b, size_t num_of_bytes) {
	void* temp = malloc(num_of_bytes);
	memcpy(temp, a, num_of_bytes);
	memcpy(a, b, num_of_bytes);
	memcpy(b, temp, num_of_bytes);
	free(temp);
}

void swap2(void** a, void** b)
{
	void* temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
void swap_template(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	TYPE a = 48;
	TYPE b = 50;
	printf("Before swap:\n");
	printf("a = %d, b = %d\n", a, b);
	//swap1(&a, &b);
	size_t num_of_bytes = sizeof(TYPE);
	//swap_void(&a, &b, num_of_bytes);
	//swap_template<TYPE>(&a, &b);
	SWAP_MACRO(a, b, TYPE);
	//swap2(&(&a), &(&a));
	printf("\n\n");
	printf("After swap:\n");
	printf("a = %d, b = %d\n", a, b);
	getchar();
	return 0;
}

