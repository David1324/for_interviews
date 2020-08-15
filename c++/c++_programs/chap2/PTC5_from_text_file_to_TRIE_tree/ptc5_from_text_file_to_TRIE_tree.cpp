/* ===== ===== =====

Theory of Programming

Trie Tree Data Structure
http://theoryofprogramming.com/2015/01/16/trie-tree-implementation/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>      // std::ifstream
#include <iostream>
#include <string>

//#define ALPHABETS 26
//#define CASE 'a'

#define ALPHABETS 256
#define CASE 0

//#define MAX_WORDS 1024

using namespace std;

struct node
{
	struct node * parent;
	struct node * children[ALPHABETS];
	vector<int> occurrences;
};

// Inserts a word 'text' into the Trie Tree
// 'trieTree' and marks it's occurence as 'index'.
void insertWord(struct node * trieTree, const char * word, int index)
{
	struct node * traverse = trieTree;
	char current_char = *word;
	while (current_char != '\0') {     // Until there is something to process
		char current_index = current_char - CASE;
		if (traverse->children[current_index] == NULL) {
			// There is no node in 'trieTree' corresponding to this alphabet

			// Allocate using calloc(), so that components are initialised
			traverse->children[current_index] = (struct node *) calloc(1, sizeof(struct node));
			traverse->children[current_index]->parent = traverse;  // Assigning parent
		}

		traverse = traverse->children[current_index];
		++word; // The next alphabet
		current_char = *word;
	}

	traverse->occurrences.push_back(index);      // Mark the occurence of the word
}

// Searches for the occurence of a word in 'trieTree',
// if not found, returns NULL,
// if found, returns poniter pointing to the
// last node of the word in the 'trieTree'
// Complexity -> O(length_of_word_to_be_searched)
struct node * searchWord(struct node * treeNode, char * word)
{
	// Function is very similar to insert() function
	char current_char = *word;
	while (current_char != '\0') {
		char current_index = current_char - CASE;
		if (treeNode->children[current_index] != NULL) {
			treeNode = treeNode->children[current_index];
			++word;
			current_char = *word;
		}
		else {
			break;
		}
	}

	if (current_char == '\0' && treeNode->occurrences.size() != 0) {
		// Word found
		return treeNode;
	}
	else {
		// Word not found
		return NULL;
	}
}

// Searches the word first, if not found, does nothing
// if found, deletes the nodes corresponding to the word
void removeWord(struct node * trieTree, char * word)
{
	struct node * trieNode = searchWord(trieTree, word);

	if (trieNode == NULL) {
		// Word not found
		return;
	}

	trieNode->occurrences.pop_back();    // Deleting the occurence

										 // 'noChild' indicates if the node is a leaf node
	bool noChild = true;

	int childCount = 0;
	// 'childCount' has the number of children the current node
	// has which actually tells us if the node is associated with
	// another word .This will happen if 'childCount' != 0.
	int i;

	// Checking children of current node
	for (i = 0; i < ALPHABETS; ++i) {
		if (trieNode->children[i] != NULL) {
			noChild = false;
			++childCount;
		}
	}

	if (!noChild) {
		// The node has children, which means that the word whose
		// occurrence was just removed is a Suffix-Word
		// So, logically no more nodes have to be deleted
		return;
	}

	struct node * parentNode;     // variable to assist in traversal

	while (trieNode->occurrences.size() == 0 && trieNode->parent != NULL && childCount == 0) {
		// trieNode->occurrences.size() -> tells if the node is associated with another word
		//
		// trieNode->parent != NULL -> is the base case sort-of condition, we simply ran
		// out of nodes to be deleted, as we reached the root
		//
		// childCount -> does the same thing as explained in the beginning, to every node
		// we reach

		childCount = 0;
		parentNode = trieNode->parent;

		for (i = 0; i < ALPHABETS; ++i) {
			if (parentNode->children[i] != NULL) {
				if (trieNode == parentNode->children[i]) {
					// the child node from which we reached
					// the parent, this is to be deleted
					parentNode->children[i] = NULL;
					free(trieNode);
					trieNode = parentNode;
				}
				else {
					++childCount;
				}
			}
		}
	}
}

// Prints the 'trieTree' in a Pre-Order or a DFS manner
// which automatically results in a Lexicographical Order
void lexicographicalPrint(struct node * trieTree, vector<char> word)
{
	int i;
	bool noChild = true;

	if (trieTree->occurrences.size() != 0) {
		// Condition trie_tree->occurrences.size() != 0,
		// is a neccessary and sufficient condition to
		// tell if a node is associated with a word or not

		vector<char>::iterator charItr = word.begin();

		while (charItr != word.end()) {
			printf("%c", *charItr);
			++charItr;
		}
		printf(" -> @ index -> ");

		vector<int>::iterator counter = trieTree->occurrences.begin();
		// This is to print the occurences of the word

		//int counter_index = 0;
		//while (counter != trieTree->occurrences.end()) {			
		//	printf("%d, ", trieTree->occurrences[counter_index]);
		//	//++counter;
		//	counter_index++;
		//}

		size_t num_of_occurrences = trieTree->occurrences.size();
		for (int i = 0; i<num_of_occurrences; i++)
		{
			printf("%d, ", trieTree->occurrences[i]);
		}

		printf("\n");
	}

	for (i = 0; i < ALPHABETS; ++i) {
		if (trieTree->children[i] != NULL) {
			noChild = false;
			char current_index = CASE + i;
			word.push_back(current_index);   // Select a child

											 // and explore everything associated with the cild
			lexicographicalPrint(trieTree->children[i], word);
			word.pop_back();
			// Remove the alphabet as we dealt
			// everything associated with it
		}
	}

	//word.pop_back();
}


void read_words_from_text_file(char* file_name, struct node * trieTree)
{
	//FILE *text_file = fopen(file_name, "r");
	//int counter = 0;
	//while (!feof(text_file))
	//{
	//	fgets(words, MAX_WORDS, text_file);
	//	counter++;
	//	printf("iteration number %d:\n", counter);
	//	printf("%s\n", words);
	//	words[strlen(words) - 1] = NULL; //removing new line /n		
	//	insertWord(trieTree, words, counter);
	//}
	//fclose(text_file);

	ifstream file;
	file.open(file_name);
	if (!file.is_open()) return;

	string word_in_file;
	int counter = 0;
	while (file >> word_in_file)
	{
		//cout << word_in_file << '\n';
		const char* word_c_str = word_in_file.c_str();
		counter++;
		insertWord(trieTree, word_c_str, counter);
	}
}



int main()
{

	vector<char> printUtil;		// Utility variable to print tree

								// Creating the Trie Tree using calloc
								// so that the components are initialised
	struct node * trieTree = (struct node *) calloc(1, sizeof(struct node));
	//char word[MAX_WORD_SIZE];


	char file_name[] = "david.txt";
	read_words_from_text_file(file_name, trieTree);



	//char word1[] = "david";
	//insertWord(trieTree, word1, 1);
	//char word2[] = "dare";
	//insertWord(trieTree, word2, 2);
	//char word3[] = "david";
	//insertWord(trieTree, word3, 3);


	printf("\n");   // Just to make the output more readable
	lexicographicalPrint(trieTree, printUtil);
	printf("\n\n");
	char word_to_search[] = "one";
	struct node * trieNode = searchWord(trieTree, word_to_search);

	if (trieNode == NULL) {
		printf("The word %s does NOT exists!\n", word_to_search);
	}
	else
	{
		printf("The word '%s' exists!\n", word_to_search);
	}

	//char word_to_delete[] = "dare";
	//removeWord(trieTree, word_to_delete);

	//printf("\n");   // Just to make the output more readable
	//lexicographicalPrint(trieTree, printUtil);
	getchar();
	return 0;
}
