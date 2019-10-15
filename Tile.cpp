#include "Tile.h"


Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::nextTetra(int next)
{
	switch (next)
	{
	case 0:
		tetras = 
		{	
			{ 1, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		};
		break;
	case 1:
		tetras =
		{ 
			{1, 0, 0, 0 },
			{1, 0, 0, 0 },
			{1, 0, 0, 0 },
			{1, 0, 0, 0 }
		};
		break;
	case 2:
		tetras =
		{
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		break;
	case 3:
		tetras =
		{
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		break;
	case 4:
		tetras =
		{
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		break;
	case 5:
		tetras = 
		{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		break;
	case 6:
		tetras =
		{
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		break;
	}
}

matrix Tile::getNextTetra()
{
	return tetras;
}



