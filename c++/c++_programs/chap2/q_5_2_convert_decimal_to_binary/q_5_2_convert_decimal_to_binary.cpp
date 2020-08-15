#include <iostream>
#include <list>

using std::list;
using std::cout;
using std::endl;

list<int> convert_decimal_to_binary(int n)
{
	list<int> binary;
	while (n > 0)
	{
		int r = n % 2;
		n = n >> 1;
		binary.push_front(r);
	}
	return binary;
}


int main()
{
	int n = 45;
	list<int> binary = convert_decimal_to_binary(44);
	list<int>::iterator i;
	for (i = binary.begin(); i != binary.end(); i++)
	{
		cout << *i;
	}
	cout << endl;
	

	getchar();
	return 0;
}