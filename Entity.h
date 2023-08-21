#pragma once

#include <array>

class Entity {
public:
    // Конструкторы
    Entity(); 
    Entity(const std::array<int, 4>& coefficients); 

    //Геттеры
    std::array<int, 4> getCoefficients() const;
    std::array<double, 3> getRoots() const;
    
    // Методы
    void mutate();
    Entity crossover(const Entity& other) const;
    void printEquation();

private:
    std::array<int, 4> coefficients;
    std::array<double, 3> roots;
};

