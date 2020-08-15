#include <iostream>
#include <set>

using namespace std;

struct Compare
{
    bool operator()(const int &a, const int &b) const
    {
        return a % 10 < b % 10;
    }
};

int main()
{
    const int a[] = {3, 2, 4, 2, 2, 2, 2, 2};
    const int count = sizeof(a) / sizeof(a[0]);
    for(int i = 0; i < count; i++)
	cout << a[i] << " ";
    cout << endl;

    set<int> s(a, a + count); 
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); ++it)
	cout << *it << " ";
    cout << endl;

    set<int, Compare>::iterator sit;
    set<int, Compare> new_s(s.begin(), s.end());
    for(sit = new_s.begin(); sit != new_s.end(); ++sit)
	cout << *sit << " ";

	cout << endl;

	// wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
   return 0;
}