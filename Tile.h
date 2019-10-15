#pragma once
#include <iostream>
#include <ctime>
#include <vector>
typedef std::vector<std::vector<int>> matrix;

class Tile
{
public:

	Tile();
	~Tile();
	void nextTetra(int next);
	matrix getNextTetra();
private:
	matrix tetras;
};
