#include <iostream>

#include "core/Environment.h"

//cmake --build build
//.\build\AdaptiCore.exe

int main()
{
    std::cout << "AdaptiCore\n" << std::endl;
    std::cout << "Adaptive Game AI Engine\n\n" << std::endl;

    Environment environment(
        10,
        5,
        {1, 3},
        {8, 0}
    );

    environment.addObstacle({2, 1});
    environment.addObstacle({3, 1});
    environment.addObstacle({6, 2});
    environment.addObstacle({8, 3});

    environment.display();

    return 0;

}