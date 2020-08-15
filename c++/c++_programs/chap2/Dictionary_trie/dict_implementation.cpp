#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>

#define first_letter 'a'
#define NUM_OF_LETTERS 26

using std::vector;
using std::cout;
using std::endl;

typedef struct Node
{
	struct Node* children[NUM_OF_LETTERS];
	struct Node* parent;
	int node_index = NUM_OF_LETTERS+10; //initialized to illegal index (the index should be between 0 to NUM_OF_LETTERS-1)
	vector<int> ocurrances;
} Node;

void insert_new_word(Node* trie, char* word, int word_index)
{
	if (strlen(word) > 0)
	{
		char current_letter = word[0];
		char current_index = current_letter - first_letter;
		if (trie->children[current_index] == NULL)
		{
			Node* child_node = (Node*)calloc(1,sizeof(Node));
			trie->children[current_index] = child_node;
			child_node->parent = trie;
			child_node->node_index = current_index;
		}
		char* sub_word = word + 1;
		insert_new_word(trie->children[current_index], sub_word, word_index);
	}
	else
	{
		trie->ocurrances.push_back(word_index);
	}
}

void print_words_lexicographic(Node* trie, vector<char> &word_to_print)
{
	for (int i = 0; i < NUM_OF_LETTERS; i++)
	{
		Node* current_node = trie->children[i];
		if (current_node != NULL)
		{
			char current_char = first_letter + i;
			word_to_print.push_back(current_char);
			for (int k=0 ; k<current_node->ocurrances.size() ; k++)
			{
				//This is the end of the word. now it's time to print it:
				int word_size = word_to_print.size();
				for (int j = 0; j < word_size; j++)
				{
					cout << word_to_print[j];
				}
				cout << endl;
			}
			print_words_lexicographic(current_node, word_to_print);
			word_to_print.pop_back();
		}
	}
}

Node* find_word(Node* trie, char* word_to_find)
{
	if (strlen(word_to_find) > 0)
	{
		char current_char = word_to_find[0];
		char current_index = current_char - first_letter;
		Node* current_node = trie->children[current_index];
		if (current_node == NULL)
		{
			return NULL;
		}
		else
		{
			char* sub_word_to_find = word_to_find + 1;
			return find_word(current_node, sub_word_to_find);
		}
	}
	else
	{
		return trie;
	}
}

void delete_word(Node* trie, char* word_to_delete)
{
	Node* word_node = find_word(trie, word_to_delete);
	if (word_node == NULL)
	{
		//word does not exist. nothing to delete
		return;
	}
	else
	{
		word_node->ocurrances.pop_back();
		if (word_node->ocurrances.size() > 0)
		{
			//there is another occurance of the same word. no node should be deleted (only reducing the number of occurances)
			return;
		}
		else
		{
			Node* parent_node = word_node->parent;
			parent_node->children[word_node->node_index] = NULL;
			free(word_node);
			char* sub_word_to_delete = word_to_delete + 1;
			return delete_word(parent_node, sub_word_to_delete);
		}
	}
}

int main()
{
	Node* trie = (Node*)calloc(1,sizeof(Node));
	char word1[] = "abc";
	insert_new_word(trie, word1, 1);
	char word2[] = "david";
	insert_new_word(trie, word2, 15);
	char word3[] = "abc";
	insert_new_word(trie, word3, 27);

	vector<char> word_to_print;
	print_words_lexicographic(trie, word_to_print);

	char word_to_delete[] = "david";
	delete_word(trie, word_to_delete);
	cout << "\n\n";
	cout << "dictonary after deleting the word " << word_to_delete << endl;
	print_words_lexicographic(trie, word_to_print);

	char word_to_find[] = "david";
	Node* word_ptr = find_word(trie, word_to_find);
	if (word_ptr == NULL)
	{
		cout << "word: '" << word_to_find << "' was not found!\n";
	}
	else
	{
		cout << "word: '" << word_to_find << "' exists!\n";
	}

	getchar();
	return 0;
}