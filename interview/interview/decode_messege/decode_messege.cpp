#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>
#include <deque>
#include <fstream>

using namespace std;

void split_stream(istream& is, vector<string>& params, char dm)
{
	string s;
	params.clear();
	while (getline(is, s, dm)) {
		params.push_back(s);
	}
}

bool find_substitution(const vector<string>& secret, const vector<string>& dict, size_t i, map<char, char> translation, deque<string>& message)
{
	if (i >= secret.size()) {
		// all words are translated
		return true;
	}

	map<char, char> trans_backup = translation;
	for (vector<string>::const_iterator it = dict.begin(); it != dict.end(); ++it) {
		if (secret[i].size() == it->size()) {
			translation = trans_backup; //david
			// contradict to the current translation?
			bool contradict = false;
			for (size_t j = 0; j < secret[i].size(); ++j) {
				map<char, char>::iterator mit = translation.find(secret[i][j]);
				if (mit != translation.end() && mit->second != (*it)[j]) {
					// contradict, try next dict word
					contradict = true;
					break;
				}
				else {
					continue;
				}
			}

			if (!contradict) {
				for (size_t j = 0; j < secret[i].size(); ++j) {
					translation[secret[i][j]] = (*it)[j];
				}
				if (find_substitution(secret, dict, i + 1, translation, message)) {
					message.push_front(*it);
					return true;
				}
			}
		}
	}
	return false;
}

void decode(const vector<string>& secret,
	const vector<string>& dict,
	deque<string>& message)
{
	map<char, char> translation;
	if (find_substitution(secret, dict, 0, translation, message)) {
		for (size_t i = 0; i < secret.size(); ++i) {
			cout << secret[i] << " ";
		}
		cout << "=";
		for (size_t i = 0; i < message.size(); ++i) {
			cout << " " << message[i];
		}
		cout << endl;
	}
}

int main(int argc, char** argv)
{
	vector<string> dict, secret;
	deque<string> message;
	//split_stream(cin, inputs, '\n');
	vector<string> inputs;
	
	

	string line;
	ifstream myfile("example.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			inputs.push_back(line);
		}
		myfile.close();
	}

	vector<string>::iterator it = inputs.begin();

	// get the dict
	if (*it == "//dict") {
		++it;
		while (it != inputs.end() && *it != "//secret") {
			dict.push_back(*it);
			++it;
		}
	}

	// decode every message
	if (it != inputs.end() && *it == "//secret") {
		++it;
		while (it != inputs.end() && *it != "//secret") {
			message.clear();
			stringstream ss(*it);
			split_stream(ss, secret, ' ');
			++it;
			decode(secret, dict, message);
		}
	}

	getchar();
	return 0;
}