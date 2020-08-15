/* f.cpp */
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

template<typename ForwardIterator>
void square(ForwardIterator first, ForwardIterator last)
{
  cout << "Squares:  ";
  for(;first != last; first++) {
    *first = (*first) * (*first);
    cout << *first << " ";
  }
  cout << endl;
}

int main()
{

  int arr[] = {1, 2, 3, 4, 5};

  vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));

  cout << "Elements: ";
  vector<int>::iterator it;
  for(it = v.begin() ; it != v.end() ; it++ ) {
    cout << *it << " ";
  }

  //for(auto it : v ) {
  //  cout << it << " ";
  //}
  cout << endl;

 square(v.begin(), v.end());


	// wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
    return 0;
}