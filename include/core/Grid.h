#pragma once

#include <vector>
#include "core/Position.h"

enum class CellType
{
    Empty,
    Obstacle
};

class Grid
{
public:
    Grid(int width, int height);

    //const at end means it can NOT modify the grid

    bool isInBounds(int x, int y) const;

    CellType getCell(int x, int y) const;

    void setCell(int x, int y, CellType type);

    void display(
        const Position& playerPosition,
        const Position& enemyPosition
    ) const;

private:
    int width_;
    int height_;

    std::vector<std::vector<CellType>> cells_;
};


