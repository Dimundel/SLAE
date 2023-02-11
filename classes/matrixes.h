#include <array>
#include <vector>

class TridiagonalMatrix {
private:
    std::vector<std::array<float, 3>> m_data;

public:
    TridiagonalMatrix(std::vector<std::array<float, 3>> data);
    std::vector<float> solve(std::vector<float> column);
};