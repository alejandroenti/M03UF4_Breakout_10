#pragma once

#include "Vector2"


class Brick {
private:
	Vector2 position;
	int health;

public:
	Brick (Vector2p, int h);
	Vector2	GetPosition();
	void SetPosition(Vector2 p);
	int GetHealth();
	void TakeDamage(int ammount);
	void Render();


};