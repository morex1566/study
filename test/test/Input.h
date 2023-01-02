/*
	파일설명 : 콘솔 입력을 담당하는 유틸리티 클래스
*/

#pragma once

#include <iostream>

class Input
{
private:
	Input();

public:
	static char GetChar();
	static int GetInt();
};