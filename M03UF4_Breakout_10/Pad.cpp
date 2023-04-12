#include "Pad.h"

int Pad::GetWidth() {
    return width;
}
Vector2 Pad::GetPosition() {
    return position;
}

void Pad::SetWidth(int w) {
    width = w;
}
void Pad::SetPosition(Vector2 p) {
    position = p;
}

int Pad::GetLifes() {
    return lifes;
}

void Pad::TakeDamage() {
    lifes--;
}

bool Pad::CheckWalls(std::vector<Wall>walls, int direction) {

    Vector2 padRight(position.x + width + 1, position.y);
    Vector2 padLeft(position.x - width - 1, position.y);

    for (auto it = walls.begin(); it != walls.end(); it++) {
        if ((it->GetPosition() == padRight && direction == 1) || (it->GetPosition() == padLeft && direction == 0))
            return false;
    }

    return true;
}

void Pad::Update(std::vector<Wall>walls) {
    
    bool pressedRight;
    bool pressedLeft;
    
    // check user input
    pressedRight = GetAsyncKeyState(VK_RIGHT) != 0;
    pressedLeft = GetAsyncKeyState(VK_LEFT) != 0;

    // move the pad, taking care of walls
    if (pressedRight) {
        if (CheckWalls(walls, 1))
            position.x += 1;
    }
    else if (pressedLeft) {
        if (CheckWalls(walls, 0))
            position.x -= 1;
    }
}

void Pad::Render() {
    // Move cursor to position
    ConsoleXY(position.x, position.y);

    // Change color
    ConsoleSetColor(ConsoleColor::CYAN, ConsoleColor::BLACK);

    // Render Pad
    std::cout << "-";
    for (int i = 0; i < width; i++) {
        ConsoleXY(position.x + i + 1, position.y);
        std::cout << "-";
        ConsoleXY(position.x - i - 1, position.y);
        std::cout << "-";
    }
}
