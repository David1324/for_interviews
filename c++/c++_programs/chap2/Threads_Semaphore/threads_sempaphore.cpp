#include <Windows.h>
#include <process.h>
#include <stdio.h>

HANDLE semaphore;
int count = 0;

void addCount(int increment)
{
	//WaitForSingleObject(semaphore, INFINITE);
#if 0
	count += increment;
#else
	int temp = count + increment;
	for (int k=0 ; k<10000 ; k++) {}
	count = temp;
#endif
	//ReleaseSemaphore(semaphore, 1, 0);
}

unsigned int __stdcall mythread(void*) 
{
	for ( int i = 0; i < 50; i++) {
		addCount(2);
	}
	return 0;
}

int main(int argc, char* argv[])
{
	HANDLE myhandleA, myhandleB;

	semaphore = CreateSemaphore(0, 1, 1, 0);

	myhandleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	myhandleB = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);

	WaitForSingleObject(myhandleA, INFINITE);
	WaitForSingleObject(myhandleB, INFINITE);

	CloseHandle(myhandleA);
	CloseHandle(myhandleB);
	
	printf("count = %d\n", count);

	getchar();

	CloseHandle(semaphore);

	return 0;
}