#pragma once

#include "Entity.h"
#include <array>

class Population {
public:
    // Конструкторы
    Population(); 
    Population(std::array<Entity, 10> newPopulation);

    const std::array<Entity, 10>& getPopulation() const;

    void printPopulation();
    std::array<double, 10> calculateFitness(std::array<double,3> targetRoots);
    std::array<int, 5> Population::selection();
    std::array<Entity, 10> Population::evolve(); // Запуск генетического алгоритма

private:
    int generationNumber;
    std::array<int, 5> sellist;
    std::array<double, 10> fitness;
    std::array<Entity, 10> population_;
};
