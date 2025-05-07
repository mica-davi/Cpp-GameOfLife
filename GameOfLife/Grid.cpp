#include "Grid.h"
void Grid::Draw() {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < columns; col++) {
			Color color = cells[row][col] ? Color{255, 255, 255, 255} : Color{ 20, 20, 20, 255 };
			DrawRectangle(col * cellpxsize, row * cellpxsize, cellpxsize-1, cellpxsize-1, color);
		}
	}
}

void Grid::UpdateGrid(std::vector<std::vector<int>> newGrid) {
	cells = newGrid;
}

void Grid::SetValue(int row, int col, int val) {
	if ((row >= 0 && row < rows) && (col >= 0 && col < columns)) {
		cells[row][col] = val;
		Color color = cells[row][col] ? Color{ 255, 255, 255, 255 } : Color{ 20, 20, 20, 255 };
		DrawRectangle(col * cellpxsize, row * cellpxsize, cellpxsize - 1, cellpxsize - 1, color);
	}
}

int Grid::GetValue(int row, int col) {
	if ((row >= 0 && row < rows) && (col >= 0 && col < columns)) {
		return cells[row][col];
	}
	return 0;
}

int Grid::GetRows() {
	return rows;
}

int Grid::GetColumns() {
	return columns;
}

void Grid::FillRandomValues() {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < columns; col++) {
			int randomVal = GetRandomValue(0, 1);
			SetValue(row, col, randomVal);
		}
	}
}

std::vector<std::vector<int>> Grid::CreateGrid() {
	return cells;
}