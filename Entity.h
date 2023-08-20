#pragma once

#include <array>

class Entity {
public:
    Entity(); // Конструктор по умолчанию
    Entity(const std::array<int, 4>& coefficients); // Конструктор с коэффициентами

    // Методы для операций с Entity
    std::array<int, 4> getCoefficients() const;
    void mutate();
    Entity crossover(const Entity& other) const;

private:
    std::array<int, 4> coefficients;
};

