#include < iostream >
#include <vector>
#include <set>

using namespace std;

set < vector < int > > find_all_zero_sets()
{
	set < vector < int > > triplets;
	vector < int > triplet(3);
	vector<int> array;
	array.push_back(-1);
	array.push_back(0);
	array.push_back(1);
	array.push_back(2);
	array.push_back(-1);
	array.push_back(-4);

	int n = array.size();

	for (int i = 0; i < n; i++)
	{
		int j = i + 1;  // first pointer 
		int k = n - 1;  // last pointer
		while (j < k)
		{

			int sum_two = array[i] + array[j];

			//case1
			if (sum_two + array[k] < 0)
				j++;

			//case2
			else if (sum_two + array[k] > 0)
				k--;

			//case3
			else
			{
				triplet[0] = array[i];
				triplet[1] = array[j];
				triplet[2] = array[k];
				triplets.insert(triplet);
				j++;
				k--;
			}
		}
	}
	return triplets;
}

int main()
{
	find_all_zero_sets();
	getchar();
	return 0;
}