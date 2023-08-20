#pragma once

#include <array>

class CubicEquation {
public:
    CubicEquation(const std::array<int, 4>& coefficients);
    std::array<double, 3> solve();
    std::array<double, 3> getRoots() const;

private:
    std::array<int, 4> coefficients_;
    std::array<double, 3> roots_;
};
