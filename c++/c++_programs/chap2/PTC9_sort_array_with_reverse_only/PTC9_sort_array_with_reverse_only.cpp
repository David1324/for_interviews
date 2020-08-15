#include <iostream>
#include <vector>
#include <climits> //INT_MIN

using std::vector;
using std::cout;
using std::endl;


vector<int> sort_using_reverse_only(vector<int> vec);
vector<int> max_sort(vector<int> vec);
vector<int> calc_reverse_arr(vector<int> vec, int index);
void print_vec(vector<int> v);




std::vector<int> sort_using_reverse_only(vector<int> vec)
{
	vector<int> sorted_vec = vec;
	//for (int i=0 ; i<vec.size() ; i++)
	//	sorted_vec.push_back(vec[i]);
	size_t n = sorted_vec.size();
	for (int i = 0; i < n; i++)
	{
		int min_val = INT_MAX;
		int min_index = INT_MAX;
		for (int j = 0; j < n - i; j++)
		{
			if (sorted_vec[j] < min_val)
			{
				min_val = sorted_vec[j];
				min_index = j;
			}
		}

		if (min_index < n - 1)
		{
			vector<int> sorted_vec = calc_reverse_arr(sorted_vec, min_index+1);
		}
		vector<int> sorted_vec = calc_reverse_arr(sorted_vec, min_index);

		//vector<int>::const_iterator first = sorted_vec.begin();
		//vector<int>::const_iterator last = sorted_vec.begin() + n - 1 - i;
		//vector<int> newVec(first, last+1);
		//vector<int> reversed_vec = calc_reverse_arr(newVec, max_j);
		//std::copy(reversed_vec.begin(), reversed_vec.end(), sorted_vec.begin());


	}
	return sorted_vec;
}

vector<int> max_sort(vector<int> vec)
{
	vector<int> sorted_vec = vec;
	size_t n = sorted_vec.size();
	for (size_t i = 0; i < n; i++)
	{
		int max_val = INT_MIN;
		size_t max_j = INT_MIN;
		for (size_t j = 0; j < n-i; j++)
		{
			if (sorted_vec[j] > max_val)
			{
				max_val = sorted_vec[j];
				max_j = j;
			}
		}
		size_t current_last_index = n - i - 1;
		int temp = sorted_vec[current_last_index];
		sorted_vec[current_last_index] = sorted_vec[max_j];
		sorted_vec[max_j] = temp;
	}
	return sorted_vec;
}

vector<int> calc_reverse_arr(vector<int> vec, int index)
{
	vector<int> reversed_vec = vec;
	size_t num_of_elements = reversed_vec.size();
	size_t last_index = index + (num_of_elements - index) / 2;
	for (size_t i = index; i < last_index; i++)
	{
		size_t current_index = num_of_elements - 1 - i + index;
		int temp = reversed_vec[current_index];
		reversed_vec[current_index] = reversed_vec[i];
		reversed_vec[i] = temp;
	}
	return reversed_vec;
}

void print_vec(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << "\n\n";
}

int main()
{
	vector<int> vec;
	vec.push_back(100);
	vec.push_back(700);
	vec.push_back(300);
	vec.push_back(600);
	vec.push_back(500);
	vec.push_back(400);
	vec.push_back(200);
	vector<int> reversed_vec = calc_reverse_arr(vec, 3);

	cout << "Original vec:" << endl;
	print_vec(vec);
	
	cout << "Reversed vec:" << endl;
	print_vec(reversed_vec);

	vector<int> sorted_vec = max_sort(vec);
	print_vec(sorted_vec);

	vector<int> sorted_vec_using_reverse_only = sort_using_reverse_only(vec);
	print_vec(sorted_vec_using_reverse_only);

	getchar();
	return 0;
}