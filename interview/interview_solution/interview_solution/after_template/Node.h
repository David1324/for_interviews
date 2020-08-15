#pragma once

template <class T>
class Node
{
private:
	T val;
	Node* m_pNext;

public:
	Node();
	Node(T value);
	void Swap(Node* pNext);
	void Reverse();
	Node* GetNext();
	void SetNext(Node*);

	T GetVal();
	void SetVal(T value);
};
