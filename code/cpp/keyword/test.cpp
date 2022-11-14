#include <iostream>

#include "global.h"

using namespace std;

int main()
{
	cout << "mecro " << MACRO_VALUE << endl;
	cout << "static " << Static_Value << endl;
	// 변수명이 같아도 해당 파일에서만의 전역변수로 인식, namespace랑 유사한듯?
	static const int Static_Value = 4;
	cout << "static " << Static_Value << endl;
	// global.h의 extern변수 링크, 어찌보면 진짜 전역변수?
	extern const int Extern_Value;
	cout << "extern " << Extern_Value << endl;

	// const와 동일한 기능... 단 컴파일 시간에 const규칙 적용시킵니다.
	// c++ 14부터 컴파일 시간에 규칙 부합X시, 런타임에 적용.
	// const는 사용에 있어서 값이 바뀌지 않는다는 것에 중점으로 사용되고,
	// constexpr는 최적화적인면의 중점으로 inline으로 지정되고, 더 엄격하게 컴파일 타임에 검사를 진행합니다.
	constexpr int constexpr_value = 10;
	// 따라서 이러한 형태도 가능합니다.
	int arr[f(10)];

	// extern과 static에 대한 레퍼런스
	// https://stackoverflow.com/questions/11055802/static-and-extern-global-variables-in-c-and-c

	// const와 constexpr에 대한 레퍼런스
	// http://www.vishalchovatiya.com/when-to-use-const-vs-constexpr-in-cpp/
	// https://stackoverflow.com/questions/14116003/whats-the-difference-between-constexpr-and-const

	return 0;
}