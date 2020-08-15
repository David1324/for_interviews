// normal_distribution
#include <iostream>
#include <string>
#include <random>
#include <vector>

using std::string;
using std::default_random_engine;
using std::normal_distribution;
using std::vector;
using std::cout;
using std::endl;

class My_hash_table
{
private:
	size_t num_of_elements;
	vector<double> vec;
	vector<vector<double>> hash_vec;
	double mean;
	double std;
	int nbins;

public:
	My_hash_table(vector<double> vec, double mean, double std, int nbins)
	{
		this->vec = vec;
		this->num_of_elements = this->vec.size();
		this->mean = mean;
		this->std = std;
		this->nbins = nbins;
		for (int i = 0; i < this->nbins; i++)
		{
			vector<double> v;
			this->hash_vec.push_back(v);
		}
		for (int i = 0; i < vec.size(); i++)
		{
			double current_val = vec[i];
			int hashed_index = hash_func(current_val);
			hash_vec[hashed_index].push_back(current_val);
		}
	}

	int calc_num_of_occurances(double val)
	{
		int hashed_index = hash_func(val);
		int counter = 0;
		for (int i = 0; i < hash_vec[hashed_index].size(); i++)
		{
			if (hash_vec[hashed_index][i] == val) counter++;
		}
		return counter;
	}

	int hash_func(double val)
	{
		size_t min_val = 0;
		size_t max_val = vec.size() - 1;
		double left_limit = mean - std;
		double right_limit = mean + std;
		double new_val = val;
		if (val < left_limit)
		{
			double nominator = abs(val - left_limit);
			double denominator = abs(min_val - left_limit);
			double factor = nominator / denominator;
			new_val = left_limit + factor * std;
		}
		else if (val > right_limit)
		{
			double nominator = abs(val - right_limit);
			double denominator = abs(max_val - right_limit);
			double factor = nominator / denominator;
			new_val = right_limit - factor * std;	
		}
		
		double bin_width = (right_limit - left_limit) / nbins;
		for (int bin_index = 0; bin_index < nbins; bin_index++)
		{
			bool condition1 = (left_limit + bin_width * bin_index) <= new_val;
			bool condition2 = (left_limit + bin_width * (bin_index+1)) > new_val;
			if (condition1 && condition2)
			{
				return bin_index;
			}
		}
		return -1; //error
	}

};

int main()
{
	const int nrolls = 1000;  // number of experiments

	double mean = 500000.0;
	double std = 100.0;
	double min_val = mean - 5;
	double max_val = mean + 5;
	int nbins = 500;

	default_random_engine generator;
	normal_distribution<double> distribution(mean, std);

	vector<double> p;


	for (int i = 0; i<nrolls; ++i) {
		double number = distribution(generator);
		p.push_back(number);
	}

	std::sort(p.begin(), p.end());

	//p[5000] = p[2000];
	//p[0] = p[5000];


	My_hash_table my_hash(p, mean, std, nbins);

	

	for (int i = 0; i < 15; i++)
	{
		int num_of_occurances = my_hash.calc_num_of_occurances(p[i]);
		cout << "The number " << p[i] << " exists " << num_of_occurances << " times" << endl;
	}
	

	getchar();

	return 0;
}