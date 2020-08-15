#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <set>

int main()
{

	//template <class OutputIterator, class Size, class T>
	//void fill_n(OutputIterator first, Size n, const T& val);
	//Fill sequence with value
	//	Assigns val to the first n elements of the sequence pointed by first.

	//list
	std::list<int> myList{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::fill_n(std::inserter(myList, std::next(myList.begin())), 3, -1);
	
	for (int n : myList) {
		std::cout << n << ' ';
	}
	std::cout << '\n';


	////multiSet
	//std::multiset<int> myMultiSet;
	//std::fill_n(std::inserter(myMultiSet, myMultiSet.begin()), 3, -1);

	//for (int n : myMultiSet) {
	//	std::cout << n << ' ';
	//}
	//std::cout << '\n';

	getchar();
}