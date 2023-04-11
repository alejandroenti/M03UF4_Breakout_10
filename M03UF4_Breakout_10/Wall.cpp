#include "Wall.h"


Wall::Wall(WallType t, Vector2 p) {
    type = t;
    position = p;
}


Vector2 Wall::GetPosition() {
    return position;
}

WallType Wall::GetType() {
    return type;
}

void Wall::Render() {
    
    // Move cursor to position
    ConsoleXY(position.x, position.y);

    // Change color
    ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);

    // Render Wall
    switch (type)
    {
    case HORIZONTAL:
        std::cout << "-";
        break;
    case VERTICAL:
        std::cout << "|";
        break;
    case CORNER:
        std::cout << "+";
        break;
    default:
        break;
    }
}