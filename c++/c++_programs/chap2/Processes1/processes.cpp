#include <Windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;

	if(argc > 1) {
		printf("Argument %s\n", argv[1]);
		printf("Starting child process\n");

		memset(&startupInfo, 0, sizeof(startupInfo));
		memset(&processInfo, 0, sizeof(processInfo));

		startupInfo.cb = sizeof(startupInfo);

		if(CreateProcess((LPCTSTR)argv[0], 0, 0, 0, 0, 0, 0, 0, 
				&startupInfo, &processInfo) == 0)
		{
			printf(" Error %d\n", GetLastError());
		}
		WaitForSingleObject(processInfo.hProcess, INFINITE);
	}
	else {
		printf("No argument\n");
	}

	getchar();

	return 0;
}