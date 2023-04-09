#pragma once

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
	void Update(Wall walls[]);
	void Render();
};