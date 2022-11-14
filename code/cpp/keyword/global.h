#pragma once

#define MACRO_VALUE 1

static const int Static_Value = 2;
const int Extern_Value = 3;

constexpr int f(int n) {
	return n > 0 ? n + f(n - 1) : n;
};