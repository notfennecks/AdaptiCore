#include "core/Environment.h"
#include "core/Combat.h"

Environment::Environment(
    int width,
    int height,
    Position playerStart,
    Position enemyStart
)
    : grid_(width, height), 
      player_(playerStart, 100), 
      enemy_(enemyStart, 100), 
      gameState_(GameState::Running)
{
}

bool Environment::movePlayer(Direction direction)
{
    if (isGameOver())
    {
        return false;
    }

    // Implementation for moving the player
    return player_.move(direction, grid_);
}

bool Environment::moveEnemy(Direction direction)
{
    if (isGameOver())
    {
        return false;
    }

    // Implementation for moving the enemy
    return enemy_.move(direction, grid_);
}

void Environment::addObstacle(Position position)
{
    grid_.setCell(
        position.x,
        position.y,
        CellType::Obstacle
    );
}

bool Environment::playerAttack()
{
    if (isGameOver())
    {
        return false;
    }

    if (!isAdjacent(
        player_.getPosition(),
        enemy_.getPosition()
    ))
    {
        return false;
    }

    enemy_.takeDamage(25);

    updateGameState();

    return true;
}

bool Environment::enemyAttack()
{
    if (isGameOver())
    {
        return false;
    }

    if (!isAdjacent(
        enemy_.getPosition(),
        player_.getPosition()
    ))
    {
        return false;
    }

    player_.takeDamage(25);

    updateGameState();

    return true;
}

void Environment::updateGameState()
{
    if (!player_.isAlive())
    {
        gameState_ = GameState::EnemyWon;
    }
    else if (!enemy_.isAlive())
    {
        gameState_ = GameState::PlayerWon;
    }
}

bool Environment::isGameOver() const
{
    return gameState_ != GameState::Running;
}

GameState Environment::getGameState() const
{
    return gameState_;
}

//For RayLib and AI state observation
const Grid& Environment::getGrid() const
{
    return grid_;
}

const Player& Environment::getPlayer() const
{
    return player_;
}

const Enemy& Environment::getEnemy() const
{
    return enemy_;
}

void Environment::display() const
{
    grid_.display(
        player_.getPosition(),
        enemy_.getPosition()
    );
}

