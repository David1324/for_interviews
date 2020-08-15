//#include <iostream>
//#include <map>
//#include <string>
//#include <utility> 
//using namespace std;
// 
//int main()
//{
//	typedef map<string, int> mapType;
//	mapType populationMap;
// 
//	populationMap.insert(pair<string, int>("China", 1339));
//	populationMap.insert(pair<string, int>("India", 1187));
//	populationMap.insert(mapType::value_type("US", 310)); 
//	populationMap.insert(mapType::value_type("Indonesia", 234)); 
//	populationMap.insert(make_pair("Brasil", 193)); 
//	populationMap.insert(make_pair("Pakistan", 170)); 
//
//	// Erase the end element using the erase function
//	// Because it's ordered map (by key), 
//	// map elements are not in the order of the entry 
//	// In this map it's US since it's ordered alphabetically.
//	mapType::iterator iter = --populationMap.end();
//	populationMap.erase(iter);
// 
//	// output the size of the map
//	cout << "Size of populationMap: " << populationMap.size() << '\n';
// 
//	for (iter = populationMap.begin(); iter != populationMap.end(); ++iter) {
//		cout << iter->first <<": " 
//			<< iter->second << " million\n";
//	}
//
//	// find will return an iterator to the matching element if it is found
//	// or to the end of the map if the key is not found
//	string country("Indonesia");
//	iter = populationMap.find(country);
//	if( iter != populationMap.end() ) 
//		cout << country <<"'s populations is "
//			<< iter->second << " million\n";
//	else
//		cout << "Key is not in populationMap" << '\n';
// 
//	// clear the entries in the map
//	populationMap.clear();
//
//	// wait until user is ready before terminating program
//    // to allow the user to see the program results
//    system("PAUSE");
//   return 0;
//}


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

void find_missing_word()
{
	map<int, string> map1;
	map<int, string> map2;

	map1.insert(pair<int, string>(1, "dog"));
	map1.insert(pair<int, string>(2, "cat"));
	map1.insert(pair<int, string>(3, "elephant"));

	map2.insert(pair<int, string>(3, "cow"));
	map2.insert(pair<int, string>(4, "elephant"));
	map2.insert(pair<int, string>(1, "dog"));
	map2.insert(pair<int, string>(2, "cat"));

	map<int, string>::iterator iter1;
	map<int, string>::iterator iter2;

	cout << "map1: " << endl;
	for (iter1 = map1.begin(); iter1 != map1.end() ; iter1++)
	{
		cout << iter1->first << ", " << iter1->second << endl;
	}
	cout << endl;

	cout << "map2: " << endl;
	for (iter2 = map2.begin(); iter2 != map2.end() ; iter2++)
	{
		cout << iter2->first << ", " << iter2->second << endl;
	}

	iter1 = map1.begin();
	iter2 = map2.begin();
	while (iter1->second == iter2->second)
	{
		iter1++;
		iter2++;
	}


	cout << endl;
	cout << endl;
	cout << endl;
	cout << "missing word is ";
	if (iter1->second < iter2->second)
	{
		cout << iter1->second << endl;
	}
	else
	{
		cout << iter2->second << endl;
	}
}

void map_try()
{
	map<string,int> words;
	map<string,int>::iterator iter;

	words["david"]=1;
	words["yoni"]=2;

	cout << "words elements: " << endl;
	for (iter = words.begin() ; iter != words.end() ; iter++)
	{
		cout << iter->first << ", " << iter->second << endl;
	}
}

void map_lyrics()
{
	const string delims(" \t,.;");
	map<string,int> words;
	string line, str;
	ifstream myFile("stairwaytoheaven1.txt", ios_base::in);
	while (getline(myFile,line)) {
		string::size_type beg, end;
		beg = line.find_first_not_of(delims);
		while (beg != string::npos) {
			end = line.find_first_of(delims,beg);
			if(end == string::npos) {
				end = line.length();
			}
			str.assign(line,beg,end-beg+1);
			++words[str];
			beg = line.find_first_not_of(delims,end);
		}
	}
	typedef map<string,int>::const_iterator iter;
	for(iter p = words.begin(); p != words.end(); ++p)
		cout << p->first << ":" << p->second << endl;

	myFile.close();
}

void read_from_file()
{
  ifstream ifp("names1.txt");

  vector<string> w(500);
  int number_of_words = read_words(w, ifp);
  w.resize(number_of_words);


  //vector<string>::iterator iter;
  //for (iter = w.begin(); iter != w.end(); ++iter)
		//cout << endl;
  //cout << endl;


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

  cout << "david: " << wMap["David_key1"] << endl;
}

int main()
{
	//read_from_file();
	//find_missing_word();
	map_lyrics();
	//map_try();

	// wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
   return 0;
}