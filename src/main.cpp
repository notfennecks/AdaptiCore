#include <iostream>

#include "core/Grid.h"
#include "entities/Player.h"
#include "entities/Enemy.h"
#include "core/Direction.h"
#include "core/Combat.h"

//cmake --build build
//.\build\AdaptiCore.exe

int main()
{
    std::cout << "AdaptiCore\n" << std::endl;
    std::cout << "Adaptive Game AI Engine\n\n" << std::endl;

    Grid grid(10, 5);

    grid.setCell(2, 1, CellType::Obstacle);
    grid.setCell(3, 1, CellType::Obstacle);
    grid.setCell(6, 2, CellType::Obstacle);
    grid.setCell(8, 3, CellType::Obstacle);

    Player player({2, 2}, 100);
    Enemy enemy({3, 2}, 100);

    if (isAdjacent(player.getPosition(), enemy.getPosition()))
    {
        enemy.takeDamage(25);
    }

    std::cout << "Enemy Health: "
              << enemy.getHealth()
              << '\n';

    grid.display(
        player.getPosition(),
        enemy.getPosition()
    );

    enemy.takeDamage(75);

    std::cout << "Enemy alive: "
              << std::boolalpha
              << enemy.isAlive()
              << '\n';

    return 0;

}