#pragma once

#include <Windows.h>

#include "Grid.h"
#include "path_finding.h"


int main()
{
	Grid grid = Grid(10, 10);

	grid.SetTypeAtPoint(GridType::StartingPoint, Point(2, 4));
	grid.SetTypeAtPoint(GridType::Destination, Point(8, 4));

	grid.SetTypeAtPoint(GridType::Obstacle, Point(5, 2));
	grid.SetTypeAtPoint(GridType::Obstacle, Point(5, 3));
	grid.SetTypeAtPoint(GridType::Obstacle, Point(5, 4));
	grid.SetTypeAtPoint(GridType::Obstacle, Point(5, 5));

	while (1)
	{
		grid.RenderGrid();

		Sleep(500);
	}
	

	return 0;
}