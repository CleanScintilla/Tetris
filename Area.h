#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include "Tile.h"
#include "BaseApp.h"

class Map
{
public:
	Map();
	~Map();
	void fillTileMatrix();
	void createTetra();
	void setPos(int x, int y);
	void PrintNextTetra(BaseApp* baseApp);
	bool Dcollision();
	bool xrCollision();
	bool xlCollision();
	void moveDown();
	void moveRight();
	void moveLeft();
	void showScore(BaseApp* baseApp);
	void showLevel(BaseApp* baseApp);
	void draw(BaseApp * baseApp);
	int rnd();
	void End();
	void rotate();
	void deleteline(float * updateSpeed);

private:

	int level;
	int score;
	const int height;
	const int width; 
	const int mapHeight;
	int next;
	const int mapWidth;
	const int mapBeginingH;
	const int border;
	int startPosX;
	int startPosY;
	int curPosX;
	int curPosY;
	float moveSpeed = 1000.0f;
	float moveTimer = 0;

	Tile tile;
	matrix buf;
	matrix nextTetra;
	matrix field;
	matrix colorMatrix;
	matrix printNext;
};


