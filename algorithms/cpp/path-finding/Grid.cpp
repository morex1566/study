#include <iostream>
#include <Windows.h>

#include "Grid.h" 

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Grid::Grid(int width_, int height_)
{
	CursorView();

	_width = width_;
	_height = height_;

	init();
}

Grid::~Grid()
{
	release();
}

void Grid::SetTypeAtPoint(GridType type_, Point point_)
{
	_map[point_.y][point_.x] = type_;
}

void Grid::RenderGrid()
{
	gotoxy(0, 0);

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			switch (_map[i][j])
			{
			case GridType::Blank:
				std::cout << std::string("□") << " ";
				break;

			case GridType::StartingPoint:
				std::cout << std::string("▣") << " ";
				break;

			case GridType::Destination:
				std::cout << std::string("◈") << " ";
				break;

			case GridType::Obstacle:
				std::cout << std::string("■") << " ";
				break;
			
			case GridType::Current:
				std::cout << std::string("★") << " ";
				break;

			default:
				break;
			}
		}

		std::cout << std::endl;
	}
}

GridType** Grid::GetMap() const
{
	return _map;
}

int Grid::GetWidth()
{
	return _width;
}

int Grid::GetHeight()
{
	return _height;
}

void Grid::init()
{
	// 공간 할당
	_map = new GridType*[_height];
	for (int i = 0; i < _height; i++)
	{
		_map[i] = new GridType[_width];
	}

	// 빈공간 타입으로 초기화
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			_map[i][j] = GridType::Blank;
		}
	}
}

void Grid::release()
{
	for (int i = 0; i < _height; i++)
	{
		delete[] _map[i];
	}

	delete[] _map;
}