#include "BaseApp.h"
#include "Area.h"
#define FALLING_NORMAL_SPD	0.35f
#define FALLING_FAST_SPD	0.01f
#define KEYBOARD_SPACE 		32
#define KEYBOARD_LEFT		75
#define KEYBOARD_RIGHT		77
#define KEYBOARD_DOWN		80

class Game : public BaseApp
{
public:
	Game();
	~Game();
	void UpdateF(float deltaTime);
	void KeyPressed(int btnCode);

private:
	Map map;
	int nextTetra;
	float updateSpeed = 0;
	float sleepTime = 0;
	float currentSpeed = FALLING_NORMAL_SPD;
};