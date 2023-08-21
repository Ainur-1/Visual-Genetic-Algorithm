#include "Entity.h"
#include "CubicEquation.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Entity::Entity() {
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        coefficients[i] = rand() % 101;
    }

    CubicEquation equation(coefficients);
    roots = equation.solve();
}

Entity::Entity(const std::array<int, 4>& coefficients) {
    this->coefficients = coefficients;

    CubicEquation equation(coefficients);
    roots = equation.solve();
}

std::array<int, 4> Entity::getCoefficients() const {
    return coefficients;
}

std::array<double, 3> Entity::getRoots() const {
    return roots;
}

void Entity::mutate() {
    int geneIndex = rand() % 4;
    coefficients[geneIndex] = rand() % 101;
}

Entity Entity::crossover(const Entity& other) const {
    int crossoverPoint = rand() % 4;
    std::array<int, 4> newCoefficients;

    for (int i = 0; i < 4; i++) {
        if (i < crossoverPoint) {
            newCoefficients[i] = coefficients[i];
        }
        else {
            newCoefficients[i] = other.coefficients[i];
        }
    }

    return Entity(newCoefficients);
}

void Entity::printEquation() {
    std::cout << std::endl << "Equation: " << coefficients[0] << "x^3 + "
        << coefficients[1] << "x^2 + " << coefficients[2] << "x + " << coefficients[3] << " = 0" << std::endl;

    std::cout << "Equation Roots: " << roots[0] << ", " << roots[1] << ", " << roots[2] << std::endl;
}