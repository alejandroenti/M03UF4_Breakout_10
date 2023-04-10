#include "Ball.h"

Ball::Ball(Vector2 p, Vector2 dir, int dmg) {
    position = p;
    direction = dir;
    damage = dmg;
}

void Ball::Bounce(Vector2 normal) {
    // update direction depending on normal
    if (normal.x == 1) {
        direction.x *= -1;
    }
    if (normal.y == 1) {
        direction.y *= -1;
    }

    // update position
    position.x += direction.x;
    position.y += direction.y;
}

int Ball::GetDamage() {
    return damage;
}
Vector2 Ball::GetDirection() {
    return direction;
}
Vector2 Ball::GetPosition() {
    return position;
}

void Ball::Update(Wall walls[], Brick bricks[], Pad pads[]) {
    // bounce() -> depende de walls, bricks y pads

       //Vector2 newPosition(position.GetX() + direction.GetX(), position.GetY() + direction.GetY());
       //position = newPosition;
    Vector2 positionObject, positionObject2;
    int normalX, normalY;
    bool found = false; // flag that represents if i found a collision

    // iterar sobre las paredes, bricks y pad(s) para ver si hay algún rebote
    for (int i = 0; i < NUM_WALLS && !found; i++) {
        positionObject = walls[i].GetPosition();
        if (positionObject.x == position.x + direction.x && positionObject.y == position.y + direction.y) {
            found = true;
            // bounce depending on wall type (horizontal, vertical, corner)
            if (walls[i].GetType() == HORIZONTAL) {
                Bounce(Vector2(0, 1));
            }
            else if (walls[i].GetType() == VERTICAL) {
                Bounce(Vector2(1, 0));
            }
            else {
                Bounce(Vector2(1, 1));
            }
        }
    }

    for (int i = 0; i < NUM_BRICKS && !found; i++) {
        positionObject = bricks[i].GetPosition();
        if (positionObject.x == position.x + direction.x && positionObject.y == position.y + direction.y) {
            found = true;
            // bounce depending on surrounding bricks
            for (int j = 0; j < NUM_BRICKS; i++) {
                positionObject2 = bricks[j].GetPosition();
                normalX = 0;
                normalY = 0;
                if (positionObject.x == positionObject2.x && positionObject.y - direction.y == positionObject2.y) {
                    normalY = 1;
                }
                if (positionObject.y == positionObject2.y && positionObject.x - direction.x == positionObject2.x) {
                    normalX = 1;
                }
            }

            Bounce(Vector2(normalX, normalY));
            bricks[i].TakeDamage(damage);
        }
    }

    for (int i = 0; i < NUM_PADS && !found; i++) {
        positionObject = pads[i].GetPosition();
        if (positionObject.x == position.x + direction.x && positionObject.y == position.y + direction.y) {
            found = true;
            if (i == 0) {
                direction.x = -1;
                direction.y = 1;
                position.x += direction.x;
                position.y += direction.y;
            }
            else if (i == 2) {
                direction.x = 1;
                direction.y = 1;
                position.x += direction.x;
                position.y += direction.y;
            }
            else {
                Bounce(Vector2(0, 1));
            }
        }
    }
}

void Ball::Render() {
    // call goToPosition(position);
    std::cout << "*";
}
