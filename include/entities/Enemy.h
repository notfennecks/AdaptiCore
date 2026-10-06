#pragma once

#include "core/Position.h"
#include "core/Direction.h"
#include "core/Grid.h"

class Enemy
{
public:
    Enemy(Position position, int health);

    Position getPosition() const;
    int getHealth() const;

    void setPosition(Position position);

    bool move(Direction direction, const Grid& grid);

    void takeDamage(int amount);
    bool isAlive() const;

private:
    Position position_;
    int health_;
};