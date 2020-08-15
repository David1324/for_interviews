#include <iostream>

using namespace std;

int count(int num)
{
	int prev = 1;
	int curr = 1;
	for (int i = 1; i < num; i++)
	{
		int next = prev + curr;
		prev = curr;
		curr = next;
	}
	return curr;
}

int main()
{
	for (int i = 1; i < 20; i++)
	{
		int res = count(i);
		cout << "count(" << i << ") = " << res << endl;
	}

	getchar();
	return 0;
}