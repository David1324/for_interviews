/* w.cpp */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int read_words(vector<string>& words, ifstream& in)
{
  int i = 0;
  while(!in.eof())
    in >> words[i++];
  return i-1;
}

int main()
{
  ifstream ifp("names");

  vector<string> w(500);
  int number_of_words = read_words(w, ifp);
  w.resize(number_of_words);


  vector<string>::iterator iter;
  for (iter = w.begin(); iter != w.end(); ++iter)
		cout << endl;
  cout << endl;


  //std::vector<std::string>::iterator iter;
  //for (iter = w.begin(); iter != w.end(); ++iter)
		//std::cout << std::endl;
  //cout << endl;


  //for(auto it : w)
  //  cout << it << " ";
  //cout << endl;

  map<string, string> wMap;

  for(int i = 0; i  <  number_of_words;) {
    wMap.insert(pair<string, string>(w[i], w[i+1]));
    i += 2;
  }

  cout << "wMap.size()=" << wMap.size() << endl;
  for(auto it = wMap.begin(); it != wMap.end(); it++)
    cout <<  it->first << " " << it->second << endl;

	// wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
   return 0;
}