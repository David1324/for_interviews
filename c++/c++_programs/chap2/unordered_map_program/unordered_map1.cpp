/* m.cpp */
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	map<unsigned long, string> employer;
	unordered_map<unsigned long, unsigned> salary;

	employer[2014021701] = "Celine Dion";
	employer[2014021702] = "Whitney Houston";

	for (auto e : employer)
		cout << "name: " << e.second
		<< "\t id: " << e.first << endl;

	unsigned total_payroll = 0;

	salary[2014021702] = 654321;
	salary[2014021701] = 123456;

	for (auto s : salary)
		total_payroll += s.second;

	cout << "total payrolls $" << total_payroll << endl;

	getchar();
	return 0;
}