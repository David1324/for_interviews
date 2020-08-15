#ifndef __SUDOKU_H_
#define __SUDOKU_H_

#include <iostream>

#define N 9

class Sudoku
{
private:
	int board[N][N];

public:
	Sudoku(int data[N][N]);
	//~Sudoku();
	void solveSudoku();
	void printSudokuBorad() const;
	//void newGame(int data[][N]);
private:
	bool solve();
	void setData(int data[][N]);
	bool ifLigalAssignment(int row, int col, int num) const;
	bool findEmptyCell(int& row, int& col) const;

	//bool ifUsedInLocalBox(int row1, int col1, int num) const;
	//bool ifUsedInRow(int row, int col, int num) const;
	//bool ifUsedInCol(int row, int col, int num) const;


};
#endif
