#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

vector<string> Permute(string str)
{	
	if (str.empty())
	{
		vector<string> vec; //empty vector
		vec.push_back("");
		return vec;
	}
	int strLength = str.length();
	string sub_string = str.substr(1, strLength-1);
	vector<string> prevList = Permute(sub_string);
	int prevListLength = prevList.size();
	vector<string> all_permutes_List;
	int fullLength = strLength*prevListLength;
	for (int i = 0; i < fullLength; i++)
	{
		all_permutes_List.push_back("");
	}

	char charToAdd = str[0];
	int current_index = 0;
	for (int i = 0; i<prevListLength; i++)
	{
		string current_string = prevList[i];
		for (int j = 0; j<strLength; j++)
		{			
			string startString = current_string.substr(0, j);
			string endString = current_string.substr(j, prevListLength);
			string full_string = "";
			full_string += startString;
			full_string += charToAdd;
			full_string += endString;
			all_permutes_List[current_index] = full_string;
			current_index++;
		}
	}
	return all_permutes_List;
}

int main()
{
	string str = "1234";
	vector<string> permutations;
	permutations = Permute(str);
	int length = permutations.size();

	for (int i = 0; i < length; i++)
	{
		cout << permutations[i] << endl;
	}


	getchar();
	return 0;
}