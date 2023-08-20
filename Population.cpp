#include "Population.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Здесь вы можете определить методы класса Population

// Конструктор
Population::Population() {
    // Инициализация случайного генератора
    srand(time(NULL));
}

// Деструктор
Population::~Population() {
    // Здесь может быть необходимый код для освобождения ресурсов
}

// Метод инициализации начальной популяции
void Population::initialize() {
    // Реализация инициализации начальной популяции
}

// Метод для запуска генетического алгоритма
void Population::evolve(int maxGenerations) {
    // Реализация генетического алгоритма
    // Включая создание, оценку приспособленности, выбор и создание новой популяции
}

// Вывод текущей популяции
void printPopulation(int Generation_Number, std::array<std::array<int, 4>, 10> new_popul) {

    std::cout << "\nGeneration " << Generation_Number << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";

    for (int i = 0; i < 10; i++) {
        std::cout << "Individual " << i << "   ";

        for (int j = 0; j < 4; j++) {
            printFormattedNumber(new_popul[i][j]);
        }

        std::cout << std::endl;
    }

}

// Вывод числа в формате с отступами
void printFormattedNumber(int num) {
    if (num == 100)
        std::cout << num << " ";
    else if (num < 10)
        std::cout << "  " << num << " ";
    else if (num >= 10 && num < 100)
        std::cout << " " << num << " ";
}