#include "Population.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Конструкторы
Population::Population() {
    srand(time(NULL));

    generationNumber = 1;

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 4; j++) {
            population_[i][j] = rand() % 101;
        }
    }   
}

Population::Population(std::array<std::array<int, 4>, 10> population) {
    generationNumber = 1;
    population_ = population;
}

// Метод для запуска генетического алгоритма
void Population::evolve(int maxGenerations) {
    // Реализация генетического алгоритма
    // Включая создание, оценку приспособленности, выбор и создание новой популяции
}

// Вывод текущей популяции
void Population::printPopulation(int Generation_Number, std::array<std::array<int, 4>, 10> population) {

    std::cout << "\nGeneration " << Generation_Number << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";

    for (int i = 0; i < 10; i++) {
        std::cout << "Individual " << i << "   ";

        for (int j = 0; j < 4; j++) {
            printFormattedNumber(population[i][j]);
        }

        std::cout << std::endl;
    }

}

// Вывод числа в формате с отступами
void Population::printFormattedNumber(int num) {
    if (num == 100)
        std::cout << num << " ";
    else if (num < 10)
        std::cout << "  " << num << " ";
    else if (num >= 10 && num < 100)
        std::cout << " " << num << " ";
}