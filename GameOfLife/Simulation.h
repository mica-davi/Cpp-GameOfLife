#pragma once
#include "Grid.h"
#include <vector>
#include <utility>
class Simulation
{
public:
	Simulation(const int& height, const int& width, const int& cellpxsize)
		: grid(height, width, cellpxsize) {};
	void Draw();
	void SetCellVal(int row, int col, int val);
	void Update();
	void GenerateRandomGrid();
	int CountLiveNeighbors(int row, int col);
private: 
	Grid grid;
	
};

