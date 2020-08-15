#include <vector>
#include <string>
#include <iostream>

using namespace std;

int Frequency[26];

int hashFunc(char c)
{
	return (c - 'a');
}

void countFre(string S)
{
	for (int i = 0; i < S.length(); ++i)
	{
		int index = hashFunc(S[i]);
		Frequency[index]++;
	}
	for (int i = 0; i < 26; ++i)
		cout << (char)(i + 'a') << ' ' << Frequency[i] << endl;
}

vector <string> hashTable[20];
int hashTableSize = 20;

void insert(string s)
{
	// Compute the index using Hash Function
	int index = hashFunc(s[0]);
	// Insert the element in the linked list at the particular index
	hashTable[index].push_back(s);
}

void search(string s)
{
	//Compute the index by using the hash function
	int index = hashFunc(s[0]);
	//Search the linked list at that specific index
	for (int i = 0; i < hashTable[index].size(); i++)
	{
		if (hashTable[index][i] == s)
		{
			cout << s << " is found!" << endl;
			return;
		}
	}
	cout << s << " is not found!" << endl;
}