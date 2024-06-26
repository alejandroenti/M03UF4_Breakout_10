#include "Ball.h"

Ball::Ball(Vector2 p, Vector2 dir, int dmg) {
    position = p;
    direction = dir;
    damage = dmg;
    score = 15;
    totalScore = 0;
}

void Ball::Bounce(Vector2 normal) {
    // update direction depending on normal
    direction = direction * normal;

    // update position
    //position = position * direction;
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

int Ball::GetScore() {
    return totalScore;
}

void Ball::Update(std::vector<Wall> walls, std::vector<Brick>& bricks, Pad* pad) {
    
    Vector2 targetPos = position + direction;

    // Check the walls
    for (auto it = walls.begin(); it != walls.end(); it++) {
        if (it->GetPosition() == position) {


            switch (it->GetType())
            {
            case HORIZONTAL:
                if (it->GetPosition().y == LAST_WALL_ROW) {
                    pad->TakeDamage();
                    position = Vector2(pad->GetPosition().x, pad->GetPosition().y - 5);
                    direction = Vector2(0, 1);
                    break;
                }
                Bounce(Vector2(1, -1));
                break;
            case VERTICAL:
                Bounce(Vector2(-1, 1));
                break;
            case CORNER:
                Bounce(Vector2(-1, -1));
                break;
            }
        }
    }

    auto brickToDestroy = bricks.end();
    int cont = 0;

    for (auto it = bricks.begin(); it != bricks.end(); it++) {
        if (it->GetPosition() == position) {
            direction.y *= -1;
            brickToDestroy = it;
            totalScore += score;
            score += 5;

            break;
        }
        cont++;
    }

    if (brickToDestroy != bricks.end())
        bricks.erase(brickToDestroy);

    for (int i = 0; i <= pad->GetWidth() * 2; i++) {
        Vector2 padPosition(pad->GetPosition().x - pad->GetWidth() + i, pad->GetPosition().y);
        if (position == padPosition) {
            if (i < pad->GetWidth()) {
                direction.x = -1;
                direction.y = -1;
            } 
            else if (i == pad->GetWidth()) {
                direction.x = 0;
                direction.y = -1;
            } 
            else {
                direction.x = 1;
                direction.y = -1;
            }
            
            score = 15;
        }
    }

    position = position + direction;
}

void Ball::Render() {

    // Move cursor to position
    ConsoleXY(position.x, position.y);

    // Change color
    ConsoleSetColor(ConsoleColor::YELLOW, ConsoleColor::BLACK);

    // Render Brick
    std::cout << "*";
}
