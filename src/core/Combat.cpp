#include "core/Combat.h"

#include <cstdlib>

bool isAdjacent(
    const Position& first,
    const Position& second
)
{
    int xDistance = std::abs(first.x - second.x);
    int yDistance = std::abs(first.y - second.y);

    return xDistance + yDistance == 1;
}