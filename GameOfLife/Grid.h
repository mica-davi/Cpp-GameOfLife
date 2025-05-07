#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
	Grid(const int& height, const int& width, const int& cellpxsize)
		: rows(height / cellpxsize), columns(width / cellpxsize), cellpxsize(cellpxsize), cells(rows, std::vector<int>(columns, 0)) {};
	void Draw();
	void SetValue(int row, int col, int val);
	int GetValue(int row, int col);
	int GetRows();
	int GetColumns();
	void UpdateGrid(std::vector<std::vector<int>> newGrid);
	std::vector<std::vector<int>> CreateGrid();
	void FillRandomValues();
private:
	int rows;
	int columns;
	int cellpxsize;
	std::vector<std::vector<int>> cells; 
};

