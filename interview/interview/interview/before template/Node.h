#pragma once


class Node
{
private:
	int val;
	Node* m_pNext;

public:
	Node();
	Node(int value);
	void Swap(Node* pNext);
	void Reverse();
	Node* GetNext();
	void SetNext(Node*);

	int GetVal();
	void SetVal(int value);
};
