//
//  Conversion - Program to convert temperature from
//             Celsius degrees into Fahrenheits:
//             Fahrenheit = Celsius  * (212 - 32)/100 + 32
//
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <string>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
#if 0
  // enter the temperature in Celsius
  int celsius;
  cout << "Enter the temperature in Celsius:";
  cin >> celsius;

  // calculate conversion factor for Celsius
  // to Fahrenheit
  int factor;
  factor = 212 - 32;

  // use conversion factor to convert Celsius
  // into Fahrenheit values
  int fahrenheit;
  fahrenheit = factor * celsius/100 + 32;

  // output the results (followed by a NewLine)
  cout << "Fahrenheit value is:";
  cout << fahrenheit << endl;
#endif

	int r=5;
	string s1("Nancy");  
	string s2("Clancy");  
	string& rs = s1;         // rs refers to s1  
  
	string *ps = &s1;        // ps points to s1<a name="31186"></a>  
  
	//rs = s2;                 // rs still refers to s1,  
							 // but s1's value is now  
							 // "Clancy"  
  
	//ps = &s2;                // ps now points to s2;  
							 // s1 is unchanged 

	cout << "rs = " << rs << endl ;
	cout << "ps = " << *ps << endl ;
	cout << "s1 = " << s1 << endl ;
	cout << "s2 = " << s2 << endl ;

  // wait until user is ready before terminating program
  // to allow the user to see the program results
  system("PAUSE");
  return 0;
}

