#pragma once

#include <array>

class Population {
public:
    Population(); // Конструктор
    ~Population(); // Деструктор

    void initialize(); // Инициализация начальной популяции
    void evolve(int maxGenerations); // Запуск генетического алгоритма

    void printPopulation(int Generation_Number, std::array<std::array<int, 4>, 10> new_popul);


private:
    int Generation_Number;
    void printFormattedNumber(int num);
};
