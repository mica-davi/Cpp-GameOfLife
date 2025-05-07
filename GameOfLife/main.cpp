#include <raylib.h> 
#include <iostream>
#include "Simulation.h"

using namespace std;

int main() {
    Color bgColor = Color{ 5, 5, 5, 255 };

    const int screenWidth = 800;
    const int screenHeight = 800;
    const int cellpxsize = 10;
    Simulation simulation(screenHeight, screenWidth, cellpxsize);

    InitWindow(screenWidth, screenHeight, "Game of Life!");
    SetTargetFPS(12);
    simulation.GenerateRandomGrid();

    std::cout << simulation.CountLiveNeighbors(39, 4) << std::endl;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(bgColor);
        simulation.Update();
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}