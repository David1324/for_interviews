#include <iostream>
using namespace std;

class B {
private:
	int n;

public:
	B(int x) :n(x) {}
	B operator+(B& b) {
		return B(n + b.n);
	}

	friend ostream& operator<<(ostream &out, const B& b) {
		out << "B: " << b.n;
		return out;
	}

	bool operator<(const B& rhs) {
		return n < rhs.n;
	}
};

int main() {
	B b1(1), b2(2), b3(3);
	const B b4 = b1 + (b2 + b3);

	cout << b4 << endl;
	getchar();
}