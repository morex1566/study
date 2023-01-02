#pragma once

#include <iostream>

class Output
{
public:
	Output();
	Output(const Output&) = delete;
	~Output();

	template <typename T1, typename... T2> static void PrintLog(T1 param1_, T2... parame2_);
	template <typename T> static void PrintLog(T param_);
};

template<typename T1, typename ...T2>
inline void Output::PrintLog(T1 param1_, T2 ...parame2_)
{
	std::cout << param1_;
	PrintLog(parame2_...);
}

template<typename T>
inline void Output::PrintLog(T param_)
{
	std::cout << param_;
}