#pragma once

class Vector2 {

public:
	int x;
	int y;

	Vector2();
	Vector2(int x, int y);

	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
};