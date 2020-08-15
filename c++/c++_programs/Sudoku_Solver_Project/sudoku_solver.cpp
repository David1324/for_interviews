#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define N 3

int num_of_empty_cells = 0;
bool temp_array[N*N];

void reset_temp_array()
{
	for (int i=0 ; i<N*N ; i++)
	{
		temp_array[i] = false;
	}
}

bool is_temp_array_filled()
{
	for (int i=0 ; i<N*N ; i++)
	{
		if (temp_array[i] == false) 
			return false;
	}
	return true;
}

bool is_value_legal(int table[N*N][N*N], int i, int j)
{
	int x, y;

	//check row
	reset_temp_array();
	for (y=0 ; y<N*N ; y++)
	{
		temp_array[table[i][y]-1] = true;
	}

	if (is_temp_array_filled == false) 
		return false;

	//check column
	reset_temp_array();
	for (x=0 ; x<N*N ; x++)
	{
		temp_array[table[x][j]-1] = true;
	}

	if (is_temp_array_filled == false) 
		return false;

	//check square
	reset_temp_array();
	int start_x = 3*(i/3);
	int start_y = 3*(j/3);
	for (x=start_x ; x<start_x+N ; x++)
	{
		for (y=start_y ; y<start_y+N ; y++)
		{
			temp_array[table[x][j]-1] = true;
		}
	}

	if (is_temp_array_filled == false) 
		return false;

	return true;
}

void fill_sudoku(int table[N*N][N*N], int i, int j)
{
	//int value;
	//bool boolTemp;
	//bool last_cell_to_fill = false;

	//if (table[i][j] == 0) //the cell is empty (not pre-filled)
	//{
	//	value = 1;
	//	table[i][j] = value;
	//	while (is_value_legal(table, i, j) == false && value <= 9)
	//	{
	//		value++;
	//		table[i][j] = value;
	//	}
	//


	//	
	//}
	//else
	//{
	//	fill_sudoku(table
	//}
}

int main()
{
        // vector with ROW rows, each row has COL columns with initial value of 99
	int table[N*N][N*N];
	fill_sudoku(table, 0, 0);
	


    // wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
	return 0;
}