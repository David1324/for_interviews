#include <set>
#include <string>
#include <iostream>

using std::string;
using std::set;
using std::cout;

//typedef set<string> DictionaryType;

int main()
{
	set<string> dictionary;
	dictionary.insert("abc123");
	dictionary.insert("xyz123");
	dictionary.insert("joe");
	dictionary.insert("joe");

	// print out the words added to the dictionary.
	size_t numElements = dictionary.size();
	set<string>::iterator it = dictionary.begin();
	while (it != dictionary.end())
	{
		cout << *it << "\n";
		++it;
	}
	getchar();
	return 0;
}