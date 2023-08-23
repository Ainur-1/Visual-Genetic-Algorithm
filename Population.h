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
    void evolve(int maxGenerations); // Запуск генетического алгоритма

private:
    int generationNumber;
    std::array<double, 10> fitness;
    std::array<Entity, 10> population_;
    void printFormattedNumber(int num);
};
