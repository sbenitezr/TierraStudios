#ifndef _GLTOOLS_H
#define _GLTOOLS_H

#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <vector>

using namespace std;

namespace gltools {
	enum { WHITE, RED, GREEN, BLUE, MAGENTA, CYAN, YELLOW, ORANGE, PURPLE, PINK, GREY, BLACK };
};


class GLTools
{
public:
	//Color utilities
	static void Color(int color, float transparency = 1.0f);
	static void BackgroundColor(int color);
	//Textures utilities
	static unsigned int LoadTexture(string filename);
	static void DeleteTextures();
	//Text utilities
	static void Print(string msg, float x = 0, float y = 0, float z = 0, int fuente = 1);				//font type {1-3} HELVETIA

//Primitives
	static void DrawEllipse(float xo, float yo, float tho, float A, float B, float C, float scale = 1);///Ax2+Bxy+Cy2
	static void DrawFrame();
	static void DrawGrid(int num_cells, float size);
	static void DrawGrid(int num_cells, float size, int col, float transparency = (1.0f));
	static void DrawExactGrid(int N, float size, int col, float transparency = (1.0f));	// draws an NxN grid, N=[2,4,6,...]

protected:
	static std::vector<string> textures_names;
	static std::vector<unsigned int> textures_ids;
};

#endif