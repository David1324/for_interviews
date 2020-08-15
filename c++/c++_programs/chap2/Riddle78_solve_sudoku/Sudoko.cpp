#include "Sudoko.h"


using std::cout;
using std::endl;

#define UN_ASSIGNED 0

int counter = 0;

Sudoku::Sudoku(int data[N][N])
{
	setData(data);
}

void Sudoku::setData(int data[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			this->board[i][j] = data[i][j];
		}
	}
}


bool Sudoku::findEmptyCell(int& row, int& col) const
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (this->board[i][j] == UN_ASSIGNED)
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool Sudoku::ifLigalAssignment(int row, int col, int num) const
{
	//Checking column col
	for (int i = 0; i < N; i++)
	{
		if (i == row)
		{
			continue;
		}
		else
		{
			if (this->board[i][col] == num)
			{
				return false;
			}
		}
	}

	//Checking row row
	for (int j = 0; j < N; j++)
	{
		if (j == col)
		{
			continue;
		}
		else
		{
			if (this->board[row][j] == num)
			{
				return false;
			}
		}
	}

	//Checking small square
	int start_row = 3 * (row / 3);
	int end_row = 3 * (row / 3) + 3;
	int start_col = 3 * (col / 3);
	int end_col = 3 * (col / 3) + 3;
	for (int i = start_row; i < end_row; i++)
	{
		for (int j = start_col; j < end_col; j++)
		{
			if (i == row && j == col)
			{
				continue;
			}
			if (this->board[i][j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

bool Sudoku::solve()
{
	counter++;
	int row, col;
	bool is_exist_empty_cell = findEmptyCell(row, col);
	if (is_exist_empty_cell)
	{
		for (int num = 1; num <= N; num++)
		{
			bool is_legal = ifLigalAssignment(row, col, num);
			if (is_legal)
			{
				this->board[row][col] = num;
				bool is_solved = this->solve();
				if (is_solved)
				{
					return true;
				}
				else
				{
					this->board[row][col] = UN_ASSIGNED;
				}
			}
		}
		return false;
	}
	return true;
}

void Sudoku::printSudokuBorad() const
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N ; j++)
		{
			cout << this->board[i][j] << ", ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void Sudoku::solveSudoku()
{
	bool is_solved = this->solve();
}


int main()
{
	int boradGame[N][N] = {
		{ 0, 7, 0, 0, 0, 5, 0, 2, 4 },
	{ 4, 0, 0, 0, 3, 0, 0, 0, 7 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 9, 2, 0, 0, 0 },
	{ 0, 2, 9, 3, 0, 8, 0, 0, 0 },
	{ 0, 8, 0, 0, 7, 0, 0, 4, 0 },
	{ 3, 0, 4, 0, 1, 7, 0, 0, 0 },
	{ 5, 0, 0, 0, 0, 9, 6, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, } };

	Sudoku *s = new Sudoku(boradGame);

	cout << "Before solving" << endl;
	s->printSudokuBorad();
	s->solveSudoku();
	std::cout << "Try number " << counter << std::endl;
	cout << "After solving" << endl;
	s->printSudokuBorad();

	getchar();
	return 0;
}