#ifndef __VECTOR2D__H__
#define __VECTOR2D__H__

class Vector {
public:
	int x;
	int y;
	Vector(int x, int y): x(x), y(y){}
	Vector(): x(-1), y(-1) {}

};
#endif