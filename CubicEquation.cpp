#include "CubicEquation.h"
#include <cmath>

CubicEquation::CubicEquation(const std::array<int, 4>& coefficients)
    : coefficients_(coefficients), roots_{ 0.0, 0.0, 0.0 } {}

std::array<double, 3> CubicEquation::solve() {
    double a = coefficients_[0];
    double b = coefficients_[1];
    double c = coefficients_[2];
    double d = coefficients_[3];

    // Calculate discriminants and intermediate values
    double discriminant = 18 * a * b * c * d - 4 * b * b * b * d + b * b * c * c - 4 * a * c * c * c - 27 * a * a * d * d;
    double delta0 = b * b - 3 * a * c;
    double delta1 = 2 * b * b * b - 9 * a * b * c + 27 * a * a * d;

    // Calculate roots
    if (discriminant > 0) {
        double C = cbrt((delta1 + sqrt(discriminant)) / 2.0);
        double D = cbrt((delta1 - sqrt(discriminant)) / 2.0);
        roots_[0] = (-b + C + D) / (3 * a);
    }
    else if (discriminant == 0) {
        roots_[0] = -b / (3 * a);
    }
    else {
        double phi = acos(delta1 / (2 * sqrt(-delta0 * delta0 * delta0)));
        double magnitude = 2 * sqrt(-delta0);
        const double pi = 3.14159265358979323846;
        roots_[0] = magnitude * cos(phi / 3) - b / (3 * a);
        roots_[1] = magnitude * cos((phi + 2 * pi) / 3) - b / (3 * a);
        roots_[2] = magnitude * cos((phi + 4 * pi) / 3) - b / (3 * a);
    }

    return roots_;
}

std::array<double, 3> CubicEquation::getRoots() const {
    return roots_;
}

std::array<int, 4> CubicEquation::getCoefficients() const{
    return coefficients_;
}