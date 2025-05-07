#include "Simulation.h"
void Simulation::Draw() {
	grid.Draw();
}
void Simulation::Update() {
	std::vector<std::vector<int>> newGrid = grid.CreateGrid();

	for (int row = 0; row < grid.GetRows(); row++) {
		for (int col = 0; col < grid.GetColumns(); col++) {
			int neighbors(CountLiveNeighbors(row, col));
			if (neighbors == 3 && !grid.GetValue(row, col)) {
				newGrid[row][col] = 1;
			}
			else if ((neighbors > 3 || neighbors < 2) && grid.GetValue(row, col)) {
				newGrid[row][col] = 0;
			}
		}
	}

	grid.UpdateGrid(newGrid);
}
void Simulation::GenerateRandomGrid() {
	grid.FillRandomValues();
}
void Simulation::SetCellVal(int row, int col, int val) {
	grid.SetValue(row, col, val);
}

int Simulation::CountLiveNeighbors(int row, int col) {
	int liveNeighbors = 0;
	std::vector<std::pair<int, int>> offsets{
		{-1, -1},
		{ 0, -1 },
		{ 1, -1 },
		{ -1, 0 },
		{ 1, 0 },
		{ -1, 1 },
		{ 0, 1 },
		{ 1, 1 }
	};
	
	for (const auto& offset : offsets) {
		const int neighborCol = (col + offset.first + grid.GetColumns()) % grid.GetColumns();
		const int neghborRow = (row + offset.second + grid.GetRows()) % grid.GetRows();
		liveNeighbors += grid.GetValue(neghborRow, neighborCol);
	}

	return liveNeighbors;
}