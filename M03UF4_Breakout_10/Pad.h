#pragma once

#include "Vector2.h"
#include "Wall.h"

class Pad {

private:
	Vector2 position;
	int width;

public:
	Pad(Vector2 p, int w);
	int GetWidth();
	void SetWidth();
	Vector2 GetPosition();
	void SetPosition();
	void Update(Wall walls[]);
	void Render();
};