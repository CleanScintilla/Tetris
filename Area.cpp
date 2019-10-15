#include "Area.h"
#include <Windows.h>
#include <conio.h>
#include <sstream>

Map::Map() :height(28), width(17), mapHeight(15), mapWidth(15), mapBeginingH(5), border(1), startPosX(mapWidth / 2 + 1),
startPosY(mapBeginingH), curPosX(startPosX), curPosY(startPosY), score(0), level(0)
{
	next = rnd();
	tile.nextTetra(next);
	this->printNext = tile.getNextTetra();
}

Map::~Map()
{
}

void Map::fillTileMatrix()
{
	field = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
}

void Map::createTetra()
{
	this->nextTetra = printNext;
	next = rnd();
	tile.nextTetra(next);
	this->printNext = tile.getNextTetra();
}

void Map::setPos(int x, int y)
{
	COORD coords;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(hOutput, coords);
}

void Map::PrintNextTetra(BaseApp* baseApp)
{
	for (int i = 0; i < 4; i++)
	{
		setPos(10, i + 22);
		for (int j = 0; j < 4; j++)
		{
			baseApp->SetChar(j + 10, i + 22, printNext[i][j] == 0 ? '.' : '#');
		}
	}
}

bool Map::Dcollision()
{
	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (nextTetra[i][j])
				{
					if  (i + curPosY + 1 >= mapHeight + mapBeginingH)
					{
						return false;
					}
					if (field[i+curPosY+1][curPosX + j])
					{
						return false;
					}
				}
			}
		}
		return true;
}

bool Map::xrCollision()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (nextTetra[i][j])
			{
				if (j + curPosX + 1 >= mapWidth + border) 
				{
					return false;
				}
				if (field[curPosY + i][curPosX + j + 1])
				{
					return false;
				}

			}
		}
	}
	return true;
}

bool Map::xlCollision()
{
	if(curPosX == 1)
	{
		return false;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (nextTetra[i][j])
			{
				if (field[i + curPosY][curPosX - 1])
				{
					return false;
				}
			}
		}
	}
	return true;
}

void Map::moveDown()
{
		if (!Dcollision())
		{
			curPosX = startPosX;
			curPosY = startPosY;
			field = buf;
			createTetra();
		}
		else
		{
			curPosY++;
		}
}

void Map::moveRight()
{
	if (xrCollision())
	{
		curPosX++;
	}
}

void Map::moveLeft()
{
	if (xlCollision())
	{
		curPosX--;
	}
}

void Map::showScore(BaseApp* baseApp)
{

	std::ostringstream score_ss;
	score_ss << score;
	std::string tempStr = score_ss.str();


	for (int i = 0; i < tempStr.size(); i++) {
		baseApp->SetChar(i + 2, 23, tempStr.c_str()[i]);
	}
}

void Map::showLevel(BaseApp* baseApp)
{

	char levelStr[10] = { '.' };

	sprintf_s(levelStr, "LEVEL: %d ", level);

	std::ostringstream level_ss;
	level_ss << "LEVEL: " << level;
	std::string tempStr = level_ss.str();


	for (int i = 0; i < tempStr.size(); i++) {
		baseApp->SetChar(i + 5, 2, tempStr.c_str()[i]);
	}
}

void Map::draw(BaseApp * baseApp)
{
	buf = field;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (nextTetra[i][j]) buf[i + curPosY][j + curPosX] = 1;
		}
	}

	setPos(0, 0);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			baseApp->SetChar(j, i, buf[i][j] == 0 ? '.' : '#');
		}
	}

	PrintNextTetra(baseApp);
	showScore(baseApp);
	showLevel(baseApp);
}

int Map::rnd()
{
	srand(time(NULL));
	return rand() % 6;
}

void Map::End()
{
	for (int j = 1; j < mapWidth; j++)
	{
		if (field[6][j])
		{
			system("cls");
			std::cout << "THE END!";
			std::cout << "\n\nPress Any Key To Continue. . . ";
			_getch();
			exit(0);
		}

	}
}

void Map::rotate()
{
	if (next != 0)
	{
		int tempY = curPosX;
		int tempX = curPosY;
		matrix transpon = nextTetra;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				transpon[i][j] = nextTetra[j][i];
			}
		}
		if (Dcollision() && xrCollision() && xlCollision())
		{
			nextTetra = transpon;
		}
	}
}

void Map::deleteline(float * updateSpeed)
{
	bool flag = false;
	for (int j = 1; j < mapWidth; j++)
	{
		if (!field[19][j])
		{
			flag = true;
			break;
		}
	}

	if (!flag)
	{
		score += 5000;
		level++;
		*updateSpeed += 0.05f;

		for (int j = 1; j <= mapWidth; j++)
		{
			setPos(j, 19);
			putchar('_');
			Sleep(20);
			field[6][j] = 0;
		}

		for (int i = 19; i >= 7; i--)
		{
			for (int j = 1; j <= mapWidth; j++)
			{
				field[i][j] = field[i - 1][j];
			}
		}
	}
}
