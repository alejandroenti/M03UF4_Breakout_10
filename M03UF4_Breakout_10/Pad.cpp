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
void Pad::Update(Wall walls[]) {
    // check user input 

    // move the pad, taking care of walls


}

void Pad::Render() {
    // Move cursor to position
    ConsoleXY(position.x, position.y);

    // Change color
    ConsoleSetColor(ConsoleColor::CYAN, ConsoleColor::BLACK);

    // Render Pad
    std::cout << "-";
}
