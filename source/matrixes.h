#include <array>
#include <vector>

#ifndef MATRIXES_H
#define MATRIXES_H

class TridiagonalMatrix {
private:
    std::vector<std::array<float, 3>> m_data;

public:
    TridiagonalMatrix(std::vector<std::array<float, 3>> data);
    int get_size() const;
    float get_item(int i, int j) const;
};

#endif