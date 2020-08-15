#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> v_input;
	vector<int> v_output;
	int n = 5;
	for (int i=0 ; i<n ; i++)
	{
		v_input.push_back(i + 1);
	}
	for (int i = 0; i < n; i++)
	{
		int min_val = i;
		int rand_num = rand();
		int index = min_val + rand_num % (n- min_val);
		v_output.push_back(v_input[index]);
		
		int temp = v_input[i];
		v_input[i] = v_input[index];
		v_input[index] = temp;
	}

	cout << "input: ";
	for (int i = 0; i < n; i++)
	{
		cout << v_input[i] << ", ";
	}
	cout << endl;

	cout << "output: ";
	for (int i = 0; i < n; i++)
	{
		cout << v_output[i] << ", ";
	}
	cout << endl;

	getchar();

}