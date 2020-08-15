#define NULL 0
class Node
{
private:
	int value;
	Node* next;

public:
	Node(int val);
	void set_next(Node* next);
	void set_value(int value);
	Node* get_next();
	int get_value();
	void reverse_node(Node* node);
};
