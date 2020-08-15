#ifndef MY_HASH_H
#define MY_HASH_H

#include <vector>

using std::vector;
#include "My_List.h"

class My_Hash
{
private:
	vector<My_List*> vec;
	int max_size;

public:
	My_Hash(int max_size);
	int hash_func(int val);
	bool check_is_exist(int val);
	void insert_val(int val);
	~My_Hash();
};

#endif
