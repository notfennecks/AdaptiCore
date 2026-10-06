#pragma once

#include "core/Direction.h"
#include "core/Grid.h"
#include "core/Position.h"
#include "entities/Player.h"
#include "entities/Enemy.h"

enum class GameState
{
    Running,
    PlayerWon,
    EnemyWon
};

class Environment
{
public:
    Environment(
        int width,
        int height,
        Position playerStart,
        Position enemyStart
    );

    bool movePlayer(Direction direction);
    bool moveEnemy(Direction direction);

    bool playerAttack();
    bool enemyAttack();

    void addObstacle(Position position);

    bool isGameOver() const;
    GameState getGameState() const;

    const Grid& getGrid() const;
    const Player& getPlayer() const;
    const Enemy& getEnemy() const;

    void display() const;

private:
    Grid grid_;
    Player player_;
    Enemy enemy_;

    GameState gameState_;

    void updateGameState();
};

