#include "Brick.h"

Brick::Brick(Vector2 p, int h) {
    position = p;
    health = h;
    color = (ConsoleColor)(9 + rand() % (13 + 1 - 9));
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
   
    // Move cursor to position
    ConsoleXY(position.x, position.y);

    // Change color
    ConsoleSetColor(color, ConsoleColor::BLACK);

    // Render Brick
    std::cout << "@";
}