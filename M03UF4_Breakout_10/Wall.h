#pragma once

#include <iostream>

#include "ConsoleControl.h"
#include "Vector2.h"

#define NUM_WALLS 50 // TO DO

enum WallType { HORIZONTAL, VERTICAL, CORNER1, CORNER2	 };

class Wall {
private:
	Vector2 position;
	WallType type;


public:
	Wall(WallType t, Vector2 p);
	Vector2 GetPosition();
	WallType GetType();
	void Render();

	//void Update(Wall walls[], Brick bricks[], Pad pads[]);



};