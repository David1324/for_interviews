#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <iostream>



int main()
{
	std::vector<std::vector<std::string> > dictionary(26);
	//'a' part
	dictionary[0].push_back("alien");
	dictionary[0].push_back("amend");
	dictionary[0].push_back("apple");

	//.......
	//'z' part
	dictionary[25].push_back("zero");
	dictionary[25].push_back("zoo");

	//sort all of the words after insert
	for (auto &strs : dictionary) {
		std::sort(std::begin(strs), std::end(strs));
	}

	//find the specific words of 'a'
	auto const it = std::equal_range(std::begin(dictionary[0]), std::end(dictionary[0]), "apple");
	if (it.first != it.second) {
		std::cout << *(it.first) << std::endl;
	}
	else {
		std::cout << "The word do not exist" << std::endl;
	}

	getchar();
	return 0;
}