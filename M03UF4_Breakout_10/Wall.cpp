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
    // go to x, y position in terminal


    if (type == VERTICAL) {
        std::cout << "|";
    }
    else if (type == HORIZONTAL) {
        std::cout << "_";
    }
    else { // TODO corner

    }
}