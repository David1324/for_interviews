#include <iostream>
#include <vector>
#include <utility>      // std::pair, std::make_pair
#include <algorithm>    // std::sort

#define START_X 1
#define END_X 2

using std::vector;
using std::pair;
using std::sort;
using std::sort;
using std::cout;
using std::endl;

bool compareFunc(const pair<float, int> &a, const pair<float, int> &b) {
	bool main_compare = a.first < b.first;
	bool secondary_compare = a.second < b.second;
	if (a.first == b.first)
		return secondary_compare;
	else
		return main_compare;
}

void print_pairs(vector<pair<float, int>> pairs)
{
	int num_of_pairs = pairs.size();
	for (int i = 0; i < num_of_pairs; i++)
	{
		pair<float, int> current_pair = pairs[i];
		cout << "[" << current_pair.first << ", " << current_pair.second << "]" << endl;
	}
}

int calculate_max_count(vector<pair<float, int>> sorted_pairs)
{
	int counter = 0;
	int max_counter = 0;
	float max_point_x = 0;
	int num_of_pairs = sorted_pairs.size();
	for (int i = 0; i < num_of_pairs; i++)
	{
		pair<float, int> current_pair = sorted_pairs[i];
		if (current_pair.second == START_X) 
			counter++;
		else 
			counter--;
		if (counter > max_counter)
		{
			max_counter = counter;
			max_point_x = current_pair.first;
		}		
	}
	return max_counter;
}

int main()
{
	vector<pair<pair<float, float>, pair<float, float>>> pairs;
	pair<float, float> pair_start1 = std::make_pair(2.5, -3.9);
	pair<float, float> pair_start2 = std::make_pair(3, 2);
	pair<float, float> pair_start3 = std::make_pair(9, 20);

	pair<float, float> pair_end1 = std::make_pair(3, 3.9);
	pair<float, float> pair_end2 = std::make_pair(7, 8);
	pair<float, float> pair_end3 = std::make_pair(30, 20);

	pair<pair<float, float>, pair<float, float>> pair1 = std::make_pair(pair_start1, pair_end1);
	pair<pair<float, float>, pair<float, float>> pair2 = std::make_pair(pair_start2, pair_end2);
	pair<pair<float, float>, pair<float, float>> pair3 = std::make_pair(pair_start3, pair_end3);

	pairs.push_back(pair1);
	pairs.push_back(pair2);
	pairs.push_back(pair3);

	int num_of_pairs = pairs.size();
	vector<pair<float, int>> pairs_x;
	for (int i = 0; i < num_of_pairs; i++)
	{
		pair<pair<float, float>, pair<float, float>> current_pair = pairs[i];
		float x_start = current_pair.first.first;
		float x_end = current_pair.second.first;
		pair<float, int> current_pair_x_start = std::make_pair(x_start, START_X);
		pair<float, int> current_pair_x_end = std::make_pair(x_end, END_X);
		pairs_x.push_back(current_pair_x_start);
		pairs_x.push_back(current_pair_x_end);
	}

	cout << "Original pairs:\n";
	print_pairs(pairs_x);
	cout << "\n\n";
	cout << "Sorted pairs:\n";
	sort(pairs_x.begin(), pairs_x.end(), compareFunc);
	print_pairs(pairs_x);

	cout << "\n\n";
	int max_counter = calculate_max_count(pairs_x);
	cout << "max_counter = " << max_counter << endl;

	getchar();
	return 0;
}