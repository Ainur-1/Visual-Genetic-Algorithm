#include "Entity.h"
#include <cstdlib>
#include <ctime>

Entity::Entity() {
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        coefficients[i] = rand() % 101;
    }
}

Entity::Entity(const std::array<int, 4>& coefficients) {
    this->coefficients = coefficients;
}

std::array<int, 4> Entity::getCoefficients() const {
    return coefficients;
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
