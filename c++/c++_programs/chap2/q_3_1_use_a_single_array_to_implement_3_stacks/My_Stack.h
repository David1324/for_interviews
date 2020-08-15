#define NULL 0

typedef struct Node
{
	int val;
	Node* next;
}Node;

class My_Stack
{
private:
	Node * top;

public:
	My_Stack();
	void push(int val);
	int pop();
};
