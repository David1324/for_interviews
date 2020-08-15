#include <iostream>
#include "My_Stack.h"

using std::cout;
using std::endl;

#define STACK_SIZE 2

int buffer[3 * STACK_SIZE];
int stack_pointer[] = { 0,0,0 }; //track top elements

void push(int stack_num, int value)
{
	int stack_top = stack_pointer[stack_num];
	/*find the index of the top element in the array+1, and increment the stack pointer */
	int index = stack_num * STACK_SIZE + stack_top;
	stack_pointer[stack_num]++;
	buffer[index] = value;
}

int pop(int stack_num)
{
	int stack_top = stack_pointer[stack_num];
	int index = stack_num * STACK_SIZE + stack_top - 1;
	stack_pointer[stack_num]--;
	int value = buffer[index];
	buffer[index] = 0;
	return value;
}

int peek(int stack_num)
{
	int index = stack_num * STACK_SIZE + stack_pointer[stack_num];
	return buffer[index];
}

bool is_empty(int stack_num)
{
	return stack_pointer[stack_num] == stack_num * STACK_SIZE;
}

void print_buffer()
{
	for (int i = 0 ; i < 3 * STACK_SIZE; i++)
	{
		cout << buffer[i] << ", ";
	}
	cout << endl;
}

int main()
{
	push(1, 3);
	push(1, 5);

	print_buffer();
	
	pop(1);
	print_buffer();

	getchar();
	return 0;
}