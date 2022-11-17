#include <queue>
#include "path_finding.h"

std::vector<Point> PathFinder2D::searchByAStar(Grid& grid, Point start, Point destination)
{
	struct Node
	{
		Point point;
		Node* parent;

		int f = g + h;
		int g, h;

		Node();
		Node(Point point_, Node* parent_, int g_, int h_)
		{
			point = point_;
			parent = parent_;
			g = g_;
			h = h_;
			f = g_ + h_;
		};
	};

	std::vector<Point> path;
	std::vector<Node> openList;
	std::vector<Node> closeList;
	
	Node current;

	#pragma region Start

	current = Node(start, nullptr, 0, 0);
	closeList.push_back(current);

	#pragma endregion

	#pragma region Update

	while (current.point != destination)
	{
		if (current.point.x > grid.GetWidth())
		{

		}
	}

	#pragma endregion


	return path;
}

std::vector<Point> PathFinder2D::searchByDStar(Grid& grid, Point start, Point destination)
{
	return std::vector<Point>();
}

std::vector<Point> PathFinder2D::searchByDjikstra(Grid& grid, Point start, Point destination)
{
	return std::vector<Point>();
}
