#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <math.h>

volatile int counter = 1;
CRITICAL_SECTION critical;

int isPrime(int n)
{
	for(int i = 2; i < (int)(sqrt((float)n) + 1.0) ; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int david=1;
unsigned int __stdcall mythread(void* lpParameter) 
{
	
	char* s;
	int threadNum = *((int*)lpParameter);
	while (counter <= 25) {
		while(!TryEnterCriticalSection(&critical)){}
		//EnterCriticalSection(&critical);
		//int number = counter++;
		int number = counter;
		for (int j=0 ; j<=100000 ; j++)	{}
		counter++;
		LeaveCriticalSection(&critical);
		s = "No";
		if(isPrime(number)) s = "Yes";


#if 1
		EnterCriticalSection(&critical);
		
		
		printf("%d. ", david);
		david++;

		if (threadNum == 2)
		{
			printf("\t\t");
		}
		printf("Thread %d value = %d is prime = %s\n", threadNum, number, s);
		LeaveCriticalSection(&critical);
#else
		if (threadNum == 2)
		{
			printf("\t\t");
		}
		printf("Thread %d value = %d is prime = %s\n", threadNum, number, s);
#endif
	}
	return 0;
}

int main(int argc, char* argv[])
{
	HANDLE myhandleA, myhandleB;

	InitializeCriticalSection(&critical);

	int a = 1;
	//myhandleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	myhandleA = (HANDLE)_beginthreadex(0, 0, &mythread, &a, 0, 0);

	int b = 2;
	//myhandleB = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	myhandleB = (HANDLE)_beginthreadex(0, 0, &mythread, &b, 0, 0);

	WaitForSingleObject(myhandleA, INFINITE);
	WaitForSingleObject(myhandleB, INFINITE);

	CloseHandle(myhandleA);
	CloseHandle(myhandleB);

	getchar();

	DeleteCriticalSection(&critical); 

	return 0;
}