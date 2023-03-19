#include "Brick.h"

Brick::Brick(Vector2 p, int h) {
    position = p;
    health = h;
}

Vector2	Brick::GetPosition() {
    return position;
}

void Brick::SetPosition(Vector2 p) {
    position = p;
}

int Brick::GetHealth() {
    return health;
}

void Brick::TakeDamage(int ammount) {
    if (ammount > health) {
        health = 0;
    }
    else {
        health = health - ammount;
    }
}

void Brick::Render() {
    // goTo...
    if (health > 0) {
        std::cout << "@";
    }
    else {
        std::cout << " ";
    }
}