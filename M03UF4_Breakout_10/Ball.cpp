#include "Ball.h"

Ball::Ball(Vector2 p, Vector2 dir, int dmg) {
    position = p;
    direction = dir;
    damage = dmg;
}

void Ball::Bounce(Vector2 normal) {

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


    // SetPosition()

}

void Ball::Render() {

}
