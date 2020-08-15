#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <math.h>

volatile int counter = 0;
HANDLE mutex;

int isPrime(int n)
{
	for(int i = 2; i < (int)(sqrt((float)n) + 1.0) ; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

unsigned int __stdcall mythread(void*) 
{
	char* s;
	while (counter < 25) {
		WaitForSingleObject(mutex, INFINITE);
		int number = counter++;
		ReleaseMutex(mutex);
		s = "No";
		if(isPrime(number)) s = "Yes";
		printf("Thread %d value = %d is prime = %s\n",
			GetCurrentThreadId(), number, s);
	}
	return 0;
}

int main(int argc, char* argv[])
{
	HANDLE myhandleA, myhandleB;

	mutex = CreateMutex(0, 0, 0);

	myhandleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	myhandleB = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)1, 0, 0);

	WaitForSingleObject(myhandleA, INFINITE);
	WaitForSingleObject(myhandleB, INFINITE);

	CloseHandle(myhandleA);
	CloseHandle(myhandleB);

	getchar();

	CloseHandle(mutex);

	return 0;
}