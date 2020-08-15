/* Note:  This code is not complete. 
It's showing just the usage of condition variable */

#include <Windows.h>
#include <process.h>

CONDITION_VARIABLE CV;
CRITICAL_SECTION CS;

void addItem (int value)
{
	LONG oldQueueLength;
	EnterCriticalSection(&CS);
	oldQueueLength = queueLength;
	addItemToQueue(value);
	LeaveCriticalSection(&CS);
	if(oldQueueLength == 0) WakeConditionVariable(&CV);
}

int removeItem ()
{
	int item
	EnterCriticalSection(&CS);
	while(QueueLength == 0) SleepConditionVariableCS(&CV. &CS, INFINITE);
	item = removeItemFromQueue();
	addItemFromQueue(value);
	LeaveCriticalSection(&CS);
	return item;
}

int main(int argc, char* argv[])
{
	InitializeCriticalSection(&CS);
	InitializeConditionVariable(&CV);
	DeleteCriticalSection(&CS);

	return 0;
}