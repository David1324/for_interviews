#include <stdio.h>
#include <stdlib.h>

double multiplyByTwo_stack(double input) {
	double temp = input * 2.0; //created on stack
	return temp;
	//temp is popped out from the stack
}

double *multiplyByTwo_heap(double *input) {
	double *temp = (double*)malloc(sizeof(double)); //created on heap;
	*temp = *input * 2.0;
	return temp;
	//temp is returned to the funtion who called this function
	//therefore it's still on the heap and needs to be freed outside this function.
}

void func_heap()
{
	int *age = (int*)malloc(sizeof(int)); //created on heap
	*age = 30;
	double *salary = (double*)malloc(sizeof(double)); //created on heap
	*salary = 12345.67;
	double *myList = (double*)malloc(3 * sizeof(double)); //created on heap
	myList[0] = 1.2;
	myList[1] = 2.3;
	myList[2] = 3.4;

	double *twiceSalary = multiplyByTwo_heap(salary);

	printf("double your salary is %.3f\n", *twiceSalary);

	free(age); //deleted from the heap
	free(salary); //deleted from the heap
	free(myList); //deleted from the heap
	free(twiceSalary); //deleted from the heap
}

void func_stack()
{
	int age = 30; //created on stack
	double salary = 12345.67; //created on stack
	double myList[3] = { 1.2, 2.3, 3.4 }; //created on stack

	printf("double your salary is %.3f\n", multiplyByTwo_stack(salary));
}

int main()
{
	func_stack();
	func_heap();

	getchar();
	return 0;
}