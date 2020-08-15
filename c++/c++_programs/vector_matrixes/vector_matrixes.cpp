#include <iostream>
#include <vector>

using namespace std;

#define ROW 3
#define COL 2

int main()
{
	// vector with ROW rows, each row has COL columns with initial value of 99
	vector<vector<int> > v2D(ROW, vector<int>(COL, 99));

	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cout << v2D[i][j] << " ";
		}
		cout << endl;
	}
	getchar();
	return 0;
}