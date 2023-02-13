#include "matrixes.h"
#include "solvers.h"
#include <iostream>

int main() {
    std::vector<std::array<float, 3>> slae1{
        {0, -2, 1}, {1, -2, 1}, {1, -2, 1}, {1, -2, 0}};
    TridiagonalMatrix mat1(slae1);
    std::vector res = solve(mat1, {0.04, 0.04, 0.04, 0.04});
    for (const auto &element : res) {
        std::cout << element << std::endl;
    }
}