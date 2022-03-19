#include <iostream>

struct Incognizable {
	int x = 0;
	int y = 0;
};

//class Incognizable
//{
//public:
//	Incognizable()
//	{
//
//	}
//
//	Incognizable(int xa)
//	{
//		a = xa;
//	}
//
//	Incognizable(int xa, int xb)
//	{
//		a = xa;
//		b = xb;
//	}
//private:
//	int a, b;
//};

int main() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = { 0 };
	Incognizable d = { 0, 1 };
	return 0;
}
