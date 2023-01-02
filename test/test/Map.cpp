#include "Map.h"

Map::Map(int width_, int height_)
{
	_width = width_;
	_height = height_;

	alloc();
}

Map::~Map()
{
	release();
}

bool Map::CheckIsMeetable()
{
	return false;
}

void Map::SetTileTypeAtPos(int x_, int y_, char type_)
{
	_map[y_][x_] = type_;
}

const char** Map::GetMap()
{
	return const_cast<const char**>(_map);
}

int Map::GetWidth()
{
	return _width;
}

int Map::GetHeight()
{
	return _height;
}

int Map::GetDate()
{
	return _date;
}

void Map::melt()
{
	// _map buffer 선언 및 할당
	char** buffer = new char* [_height];
	for (int i = 0; i < _height; i++)
	{
		buffer[i] = new char[_width];
	}

	// buffer 초기화 로직
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			switch (_map[i][j])
			{
			case '.':
				buffer[i][j] = '.';
				break;

			case 'L':
				buffer[i][j] = 'L';
				break;

			case 'X':
				// 상하좌우 물인지 확인
				if (i - 1 >= 0 && _map[i - 1][j] == '.')
				{
					buffer[i][j] = '.';
					break;
				}

				if (i + 1 <= _height - 1 && _map[i + 1][j] == '.')
				{
					buffer[i][j] = '.';
					break;
				}

				if (j - 1 >= 0 && _map[i][j - 1] == '.')
				{
					buffer[i][j] = '.';
					break;
				}
				
				if (j + 1 <= _width - 1 && _map[i][j + 1] == '.')
				{
					buffer[i][j] = '.';
					break;
				}

				buffer[i][j] = 'X';
				break;

			default:
				break;
			}
		}
	}

	// buffer와 _map 교체
	char** temp = _map;
	_map = buffer;
	buffer = temp;
	
	// _map buffer 제거
	for (int i = 0; i < _height; i++)
	{
		delete[] temp[i];
	}
	delete[] temp;
}

void Map::alloc()
{
	_map = new char* [_height];
	for (int i = 0; i < _height; i++)
	{
		_map[i] = new char[_width];
	}
}

void Map::release()
{
	for (int i = 0; i < _height; i ++)
	{
		delete[] _map[i];
	}

	delete[] _map;
}
