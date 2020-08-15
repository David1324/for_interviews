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

  
  map<unsigned long, string>::iterator e;

  for(e = employer.begin() ; e != employer.end() ; e++)
  {
    cout << "name: " << e->second << "\t id: "  << e->first << endl;
  }
  
  //for(auto e: employer)
  //  cout << "name: " << e.second
  //        << "\t id: "  << e.first << endl;

  unsigned total_payroll = 0;

  salary[2014021702] = 60;
  salary[2014021701] = 40;

  unordered_map<unsigned long, unsigned>::iterator s;

  for(s = salary.begin() ; s != salary.end() ; s++)
    total_payroll += s->second;

  //for(auto s: salary)
  //  total_payroll += s.second;

  cout << "total payrolls $" << total_payroll << endl;

	// wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
   return 0;
}