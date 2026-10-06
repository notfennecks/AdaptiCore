#include "core/Grid.h"

#include <iostream>

Grid::Grid(int width, int height)
    : width_(width),
      height_(height),
      cells_(height, std::vector<CellType>(width, CellType::Empty))
{

}

//Checking to see if cell is inside the grid, returns true or false
bool Grid::isInBounds(int x, int y) const
{
    return x >= 0 &&
           x < width_ &&
           y >= 0 &&
           y < height_;
}

//Get a specific cell with given coordinates
CellType Grid::getCell(int x, int y) const
{
    return cells_[y][x];
}

//Set the type of a specific cell with given coordinates
void Grid::setCell(int x, int y, CellType type)
{
    if (!isInBounds(x, y))
    {
        return;
    }

    cells_[y][x] = type;
}

void Grid::display(
    const Position& playerPosition,
    const Position& enemyPosition
) const
{
    for (int y = 0; y < height_; ++y)
    {
        for (int x = 0; x < width_; ++x)
        {
            Position current{x, y};

            if (current == playerPosition)
            {
                std::cout << "P ";
            }
            else if (current == enemyPosition)
            {
                std::cout << "E ";
            }
            else
            {
                switch (cells_[y][x])
                {
                    case CellType::Empty:
                        std::cout << ". ";
                        break;

                    case CellType::Obstacle:
                        std::cout << "# ";
                        break;
                }
            }
        }

        std::cout << '\n';
    }
}