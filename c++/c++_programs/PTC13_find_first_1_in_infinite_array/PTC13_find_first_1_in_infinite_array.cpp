// C++ program to demonstrate working of an algorithm that finds
// an element in an array of infinite size
#include<iostream>
using namespace std;

// Simple binary search algorithm
int binarySearch(int arr[], int left, int right)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]==0 && arr[mid+1]==1)
			return mid+1;
		if (arr[mid] == 0)
			return binarySearch(arr, mid + 1, right);
		else
			return binarySearch(arr, left, mid - 1);
		
	}
	return -1;
}

// function takes an infinite size array and a key to be
//  searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be
// infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE
// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING
int findPos(int arr[])
{
	int low = 0, high = 1;
	int val = arr[0];
	

	// Find h to do binary search
	while (val==0)
	{
		low = high;        // store previous high
		high = 2 * high;      // double high index
		val = arr[high]; // update new val
	}

	// at this point we have updated low and
	// high indices, Thus use binary search 
	// between them
	return binarySearch(arr, low, high);
}

// Driver program
int main()
{
	//int arr[] = { 3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170 };
	//int ans = findPos(arr, 10);

	int arr[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1};
	int ans = findPos(arr);
	if (ans == -1)
		cout << "Element not found";
	else
		cout << "Element found at index " << ans;

	getchar();
	return 0;
}