#include "context.h"
#include "render.h"
#include "textLoader.h"
#include <string>

int main() 
{
	context game;
	game.init(640, 480, "Triangle");

	vertex triVerts[] = 
	{ 
		{{-0.5f, -0.5f, 0, 1}}, 
		{{0.5f, -0.5f, 0, 1}},
		{{0, 0.5, 0, 1}}
	};

	unsigned int triIndices[] = { 0, 1, 2 };

	geometry triangle = makeGeometry(triVerts, 3, triIndices, 3);

	std::string basicVert = PrintFile("shaders/vert1.txt");

	std::string basicFrag = PrintFile("shaders/frag1.txt");

	shader basicShade = makeShader(basicVert.c_str(), basicFrag.c_str());

	while (!game.shouldClose())
	{
		game.tick();
		game.clear();

		draw(basicShade, triangle);
	}

	game.term();

	return 0;
}