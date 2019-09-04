#include "context.h"
#include "render.h"
#include "textLoader.h"
#include <string>
#include "glm/glm.hpp"
#include "glm/ext.hpp"

#include <cassert>
int main() 
{
	context game;
	game.init(640, 480, "Triangle");

	vertex triVerts[] = 
	{ 
		{ { -0.5f, -0.5f, 0, 1}, { 0, 0, 1, 0 }, { 0, 0 }, { 1, 0, 0, 1 } },
		{ { 0.5f, -0.5f, 0, 1}, { 0, 0, 1, 0 }, { 1, 0 }, { 0, 1, 0, 1 } },
		{ { 0, 0.5, 0, 1}, { 0, 0, 1, 0 }, { 0.05f, 1.0f }, { 0, 0, 1, 1 } }
	};

	unsigned int triIndices[] = { 0, 1, 2 };

	geometry triangle = makeGeometry(triVerts, 3, triIndices, 3);

	std::string basicVert = PrintFile("shaders/vert1.txt");

	std::string basicFrag = PrintFile("shaders/frag1.txt");

	shader basicShade = makeShader(basicVert.c_str(), basicFrag.c_str());

	glm::mat4 triModel = glm::identity<glm::mat4>();

	glm::mat4 camProj = glm::perspective(glm::radians(70.0f), 640.0f / 480.0f, 0.1f, 100.0f);
	glm::mat4 camView = glm::lookAt(glm::vec3(0, 0, -10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	texture triTex = loadTexture("textures/soulspear_diffuse.tga");

	light sun;
	sun.direction = glm::vec3{ 1, 1, 1 };
	sun.color = glm::vec4{ 1, 0, 0, 1 };

	setUniform(basicShade, 0, camProj);
	setUniform(basicShade, 1, camView);
	setUniform(basicShade, 3, triTex, 0);
	setUniform(basicShade, 4, sun.direction);
	setUniform(basicShade, 5, sun.color);

	triModel = glm::rotate(triModel, glm::radians(180.0f), glm::vec3(0, 1, 0));

	while (!game.shouldClose())
	{
		game.tick();
		game.clear();

		//triModel = glm::rotate(triModel, glm::radians(5.0f), glm::vec3(0, 1, 0));

		if (sun.color.x == 0 && sun.color.y == 1 && sun.color.z != 1)
		{
			sun.color.z = glm::min(1.0f, sun.color.z + 0.1f);
		}
		else if (sun.color.x == 1 && sun.color.y == 0 && sun.color.z != 0)
		{
			sun.color.z = glm::max(0.0f, sun.color.z - 0.1f);
		}
		else if (sun.color.x == 1 && sun.color.y != 1 && sun.color.z == 0)
		{
			sun.color.y = glm::min(1.0f, sun.color.y + 0.1f);
		}
		else if (sun.color.x == 0 && sun.color.y != 0 && sun.color.z == 1)
		{
			sun.color.y = glm::max(0.0f, sun.color.y - 0.1f);
		}
		else if (sun.color.x != 1 && sun.color.y == 0 && sun.color.z == 1)
		{
			sun.color.x = glm::min(1.0f, sun.color.x + 0.1f);
		}
		else if (sun.color.x != 0 && sun.color.y == 1 && sun.color.z == 0)
		{
			sun.color.x = glm::max(0.0f, sun.color.x - 0.1f);
		}

		setUniform(basicShade, 2, triModel);
		setUniform(basicShade, 5, sun.color);

		draw(basicShade, triangle);
	}

	game.term();

	return 0;
}