#pragma once

#include <vector>
#include <Windows.h>

#include "ConsoleControl.h"
#include "Vector2.h"
#include "Wall.h"

#define NUM_PADS 3

class Pad {

private:
	Vector2 position;
	int width;

public:
	Pad(Vector2 p, int w)
		: position(p), width(w) {}
	int GetWidth();
	void SetWidth(int w);
	Vector2 GetPosition();
	void SetPosition(Vector2 p);
	bool CheckWalls(std::vector<Wall>walls, int direction); // 0 LEFT 1 RIGHT
	void Update(std::vector<Wall>walls);
	void Render();
};