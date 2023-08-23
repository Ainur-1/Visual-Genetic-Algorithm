#include "Population.h"
#include "Entity.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Конструкторы
Population::Population() {
    generationNumber = 1;

    for (int i = 0; i < 10; i++) {

        population_[i] = Entity::Entity();
    }
}

Population::Population(std::array<Entity, 10> newPopulation) {
    generationNumber = 1;
    population_ = newPopulation;
}

const std::array<Entity, 10>& Population::getPopulation() const {
    return population_;
}

// Метод для запуска генетического алгоритма
void Population::evolve(int maxGenerations) {
    // Реализация генетического алгоритма
    // Включая создание, оценку приспособленности, выбор и создание новой популяции
}

// Оценка приспособленности особей (близость к корням)
std::array<double, 10> Population::calculateFitness(std::array<double, 3> target_roots) {
    for (int i = 0; i < 10; i++) {
        double total_distance = 0.0;

        for (int j = 0; j < 3; j++) {
            std::array<double, 3> roots = population_[i].getRoots();

            for (int k = 0; k < 3; k++) {
                double distance = std::abs(roots[k] - target_roots[j]);
                total_distance += distance;
            }
        }

        fitness[i] = 1.0 / total_distance;
    }

    return fitness;
}

// Вывод текущей популяции
void Population::printPopulation() {

    std::cout << "\nGeneration " << generationNumber << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";

    for (int i = 0; i < 10; i++) {
        std::cout << "Individual " << i << "   ";

        for (int j = 0; j < 4; j++) {
            printFormattedNumber(population_[i][j]);
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