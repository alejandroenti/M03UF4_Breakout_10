#pragma once
#include <iostream>
#include <stdlib.h>

#include "ConsoleControl.h"
#include "Vector2.h"

class Brick {
private:
	Vector2 position;
	int health;
	ConsoleColor color;

public:
	Brick(Vector2 p, int h);
	Vector2	GetPosition();
	void SetPosition(Vector2 p);
	int GetHealth();
	void TakeDamage(int ammount);
	void Render();


};