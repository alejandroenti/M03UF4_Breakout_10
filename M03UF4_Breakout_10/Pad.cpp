#include "Pad.h"

Pad::Pad(Vector2 p, int w) {
    position = p;
    width = w;
}

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
    // call goToPosition(position);
    std::cout << "---";
}
