// ============================================================================
//     Author: K Perkins
//     Date:   Jan 31, 2013
//     Taken From: http://programmingnotes.org/
//     File:  SpellCheck.cpp
//     Description: This is a simple spell checker which tests the HashTable.h
//          class. 
// ============================================================================
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>
#include "HashTable.h"
using namespace std;

// iterator declaration for hash table
typedef HashTable<string>::Iterator iterDec;

// hash table size
const int TABLE_SIZE = 19000;

// strtok delimiters
//const char* DELIMITERS = " ,.-\':;?()+*/\\%$#!\"@\^&";
const char* DELIMITERS = " ,.-\':;?()+*/\\%$#!\"@";

// function prototypes
void PrintTableStats(HashTable<string>& hashTable);
int SpellCheck(HashTable<string>& hashTable, string word);
string ToLowerCase(string word);

int main()
{
	// declare variables
	int result = 0;
	string userInput;
	string currWord;
	clock_t beg; // used to time the hashtable load
	clock_t end; // used to time the hashtable load
	char response;
	ifstream infile;
	HashTable<string> hashTable(TABLE_SIZE);

	// open the dictionary file
	infile.open("david.txt");

	// check if the file exists, EXIT if it doesnt
	if (infile.fail())
	{
		cout << "nn**ERROR - The dictionary file could not be found...n";
		exit(1);
	}

	cerr << "nLoading dictionary....";
	beg = clock(); // start the timer

				   // get data from file and put into hashtable
	while (infile >> currWord)
	{
		// makes sure duplicate words arent inserted into table
		if (!hashTable.Count(currWord))
		{
			hashTable.Insert(currWord);
		}
	}
	infile.close();
	PrintTableStats(hashTable);

	end = clock() - beg; // end the timer
	cout << "nnDictionary loaded in " <<
		(double)end / ((double)CLOCKS_PER_SEC) << " secs!";

	// creates a line separator
	cout << endl;
	cout.fill('-');
	cout << left << setw(50) << "" << endl;

	do { // get user input
		cout << "n>> Please enter a sentence: ";
		getline(cin, userInput);
		cout << endl;

		// split each word from the string into individual words to check if 
		// they are spelled correctly 
		char* splitInput = strtok(const_cast<char*>(userInput.c_str()), DELIMITERS);
		while (splitInput != NULL)
		{
			currWord = splitInput;
			currWord = ToLowerCase(currWord);
			result += SpellCheck(hashTable, currWord);
			splitInput = strtok(NULL, DELIMITERS);
		}

		// display results		
		if (result > 0)
		{
			cout << "Number of words spelled incorrectly: " << result << endl;
			result = 0;
		}

		// ask for more data
		cout << "nDo you want to enter another sentence? (y/n): ";
		cin >> response;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the cin buffer
	} while (toupper(response) == 'Y');

	cout << "nBYE!!n";
	getchar();

	return 0;
}// end of main

void PrintTableStats(HashTable<string>& hashTable)
{
	int largestBucket = -9999999;
	int largestIndex = 0;
	int smallestBucket = 9999999;
	int smallestIndex = 0;
	double numBuckestUsed = 0;
	ofstream outfile("OUTPUT_HashTable_Stats_programmingnotes_freeweq_com.txt");

	for (int x = 0; x < hashTable.TableSize(); ++x)
	{
		// iterator is used to traverse each hashtable bucket
		iterDec it = hashTable.begin(x);
		if (!hashTable.IsEmpty(x))
		{
			if (smallestBucket > hashTable.BucketSize(x))
			{
				smallestBucket = hashTable.BucketSize(x);
				smallestIndex = x;
			}
			if (largestBucket < hashTable.BucketSize(x))
			{
				largestBucket = hashTable.BucketSize(x);
				largestIndex = x;
			}
			++numBuckestUsed;
			outfile << "nBucket #" << x << ":\n";
			for (int y = 0; y < hashTable.BucketSize(x); ++y)
			{
				outfile << "\t" << it[y] << endl;
			}
		}
	}
	cout << "Complete!n";

	// creates a line separator
	cout << endl;
	cout.fill('-');
	cout << left << setw(50) << "" << endl;

	cout << "Total dictionary words = " << hashTable.TotalElems() << endl
		<< "Hash table size = " << hashTable.TableSize() << endl
		<< "Largest bucket size = " << largestBucket << " items at index #" << largestIndex << endl
		<< "Smallest bucket size = " << smallestBucket << " items at index #" << smallestIndex << endl
		<< "Total buckets used = " << numBuckestUsed << endl
		<< "Total percent of hash table used = " << (numBuckestUsed / hashTable.TableSize()) * 100 << "%" << endl
		<< "Average bucket size = " << (hashTable.TotalElems() / numBuckestUsed) << " items";
}// end of PrintTableStats

int SpellCheck(HashTable<string>& hashTable, string word)
{
	int result = 0;
	int suggestion = 0;
	string remove[256];
	int numRemove = 0;

	if (!hashTable.Count(word))
	{
		++result;
		cout << "** " << word << ": ";
		// alteration & insertion
		for (unsigned x = 0; x < word.length(); ++x)
		{
			string alteration = word;
			for (char c = 'a'; c <= 'z'; ++c)
			{
				//alteration
				alteration[x] = c;
				if (hashTable.Count(alteration))
				{
					cout << alteration << ", ";
					remove[numRemove++] = alteration;
					++suggestion;
					// remove the entry so it isnt displayed multiple times
					hashTable.Remove(alteration);
				}
				//insertion
				string insertion = word.substr(0, x) + c + word.substr(x);
				if (hashTable.Count(insertion))
				{
					cout << insertion << ", ";
					remove[numRemove++] = insertion;
					++suggestion;
					// remove the entry so it isnt displayed multiple times
					hashTable.Remove(insertion);
				}
			}
		}
		// transposition & deletion	
		for (unsigned x = 0; x < word.length() - 1; ++x)
		{
			// transposition 
			string transposition = word.substr(0, x) + word[x + 1] + word[x] + word.substr(x + 2);
			if (hashTable.Count(transposition))
			{
				cout << transposition << ", ";
				remove[numRemove++] = transposition;
				++suggestion;
				// remove the entry so it isnt displayed multiple times
				hashTable.Remove(transposition);

			}
			// deletion
			string deletion = word.substr(0, x) + word.substr(x + 1);
			if (hashTable.Count(deletion))
			{
				cout << deletion << ", ";
				remove[numRemove++] = deletion;
				++suggestion;
				// remove the entry so it isnt displayed multiple times
				hashTable.Remove(deletion);
			}
		}
		// place the removed items back inside the hash table
		while (numRemove >= 0)
		{
			hashTable.Insert(remove[numRemove--]);
		}
		if (suggestion < 1)
		{
			cout << "No spelling suggestion found...";
		}
		cout << endl << endl;
	}
	return result;
}// end of SpellCheck

string ToLowerCase(string word)
{
	for (unsigned x = 0; x < word.length(); ++x)
	{
		word[x] = tolower(word[x]);
	}
	return word;
}// http://programmingnotes.org/