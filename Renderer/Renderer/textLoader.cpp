#include "textLoader.h"
#include <iostream>
#include <fstream>

std::string PrintFile(const char* filename)
{
	std::string shaderText;
	std::string line;
	std::fstream shaderFile(filename);
	if (shaderFile.is_open())
	{
		while (std::getline(shaderFile, line))
		{
			shaderText += line + '\n';
		}
		shaderFile.close();
	}
	else std::cout << "\nError: \"" << filename << "\" shader file not found.";
	return shaderText;
}
