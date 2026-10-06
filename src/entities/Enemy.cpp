#include "entities/Enemy.h"

Enemy::Enemy(Position position, int health)
     : position_(position),
       health_(health)
{

}

Position Enemy::getPosition() const
{
    return position_;
}

int Enemy::getHealth() const
{
    return health_;
}

void Enemy::setPosition(Position position)
{
    position_ = position;
}

bool Enemy::move(Direction direction, const Grid& grid)
{
    Position newPosition = position_;

    switch (direction)
    {
        case Direction::Up:
            --newPosition.y;
            break;
        case Direction::Down:
            ++newPosition.y;
            break;
        case Direction::Left:
            --newPosition.x;
            break;
        case Direction::Right:
            ++newPosition.x;
            break;
    }

    if (!grid.isInBounds(newPosition.x, newPosition.y))
    {
        return false;
    }
    if (grid.getCell(newPosition.x, newPosition.y) == CellType::Obstacle)
    {
        return false;
    }

    position_ = newPosition;
    
    return true;
}

void Enemy::takeDamage(int amount)
{
    health_ -= amount;

    if (health_ < 0)
    {
        health_ = 0;
    }
}

bool Enemy::isAlive() const
{
    return health_ > 0;
}