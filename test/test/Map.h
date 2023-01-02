/*
	파일 설명 : 타일 사이즈, 타일 정보를 포함하는 인스턴싱 가능한 클래스
*/

#pragma once

class Map
{
public:
	Map(int width_, int height_);
	~Map();

	// 백조가 서로 만날 수 있는지 확인
	bool CheckIsMeetable();

	void SetTileTypeAtPos(int x_, int y_, char type_);
	const char** GetMap();
	int GetWidth();
	int GetHeight();
	int GetDate();

private:
	// 가장자리 얼음이 녹음
	void melt();
	// 클래스 내의 모든 동적 객체 메모리 할당
	void alloc();
	// 클래스 내의 모든 동적 객체 메모리 해제
	void release();

private:
	int _width, _height, _date;
	char** _map;
};

