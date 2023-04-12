#pragma once

#include <vector>

#include "Vector2.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"

#define LAST_WALL_ROW 13

class Ball {

private:
	Vector2 position;
	Vector2 direction;
	int damage;
	int score;
	int totalScore;

public:
	Ball(Vector2 p, Vector2 dir, int dmg);
	void Bounce(Vector2 normal);
	int GetDamage();
	Vector2 GetDirection();
	Vector2 GetPosition();
	int GetScore();
	void Update(std::vector<Wall> walls, std::vector<Brick>& bricks, Pad* pad);
	void Render();
};