#pragma once

#include <array>

class Population {
public:
    // Конструкторы
    Population(); 
    Population(std::array<std::array<int, 4>, 10> population);

    void evolve(int maxGenerations); // Запуск генетического алгоритма
    void printPopulation(int Generation_Number, std::array<std::array<int, 4>, 10> population);


private:
    int generationNumber;
    std::array<std::array<int, 4>, 10> population_;
    void printFormattedNumber(int num);
};
