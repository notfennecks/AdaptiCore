#include "entities/Player.h"

Player::Player(Position position, int health)
    : position_(position),
      health_(health)
{

}

Position Player::getPosition() const
{
    return position_;
}

int Player::getHealth() const
{
    return health_;
}

void Player::setPosition(Position position)
{
    position_ = position;
}

bool Player::move(Direction direction, const Grid& grid)
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

    //Check if new requested position is within bounds
    if (!grid.isInBounds(newPosition.x, newPosition.y))
    {
        return false;
    }

    //Check if the new position is an obstacle
    if (grid.getCell(newPosition.x, newPosition.y) == CellType::Obstacle)
    {
        return false;
    }

    //If all checks pass, update the player's position
    position_ = newPosition;
    return true;
    
}

void Player::takeDamage(int amount)
{
    health_ -= amount;

    if (health_ < 0)
    {
        health_ = 0;
    }
}

bool Player::isAlive() const
{
    return health_ > 0;
}