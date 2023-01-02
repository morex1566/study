#include "Input.h"

char Input::GetChar()
{
	char key;
	std::cin >> key;

	return key;
}

int Input::GetInt()
{
	int key;
	std::cin >> key;

	return key;
}
