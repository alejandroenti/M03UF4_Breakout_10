#pragma once
#include <iostream>
#include "Vector2.h"

#define NUM_BRICKS 72

class Brick {
private:
	Vector2 position;
	int health;

public:
	Brick(Vector2 p, int h);
	Vector2	GetPosition();
	void SetPosition(Vector2 p);
	int GetHealth();
	void TakeDamage(int ammount);
	void Render();


};