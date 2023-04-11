#pragma once

class Vector2 {

public:
	int x;
	int y;

	Vector2();
	Vector2(int x, int y);
	Vector2 operator+ (Vector2& other) {
		Vector2 result(x + other.x, y + other.y);
		return result;
	};
	bool operator== (Vector2& other) {
		return x == other.x && y == other.y;
	}
};