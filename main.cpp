#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "CubicEquation.h"
#include "Entity.h"
#include "Population.h"

int main() {
    srand(time(NULL));

    const int MAX_GENERATIONS = 100; // Максимальное количество поколений

    std::cout << "New Genetic Algorithm for Cubic Equation\n\n";

    std::array<int, 4> coefficients; // Коэффициенты кубического уравнения

    // Ввод коэффициентов
    std::cout << "Enter the coefficients a, b, c, and d: " << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cin >> coefficients[i];
    }

    Entity targetEquation(coefficients);
    targetEquation.printEquation();

    std::array<double, 3> roots = targetEquation.getRoots();
    
    Population newPopul;
    newPopul.printPopulation();

    int Generation_Number = 1;
    std::array<Entity, 10> new_popul = newPopul.getPopulation();

    std::array<int, 5> sellist; // Массив наиболее приспособленных.


    // Основной цикл генетического алгоритма
    while (true) {
        // Оценка приспособленности
        newPopul.calculateFitness(roots);

        // Выбор особей для следующего поколения
        sellist = newPopul.selection();

        // Создание новой популяции на основе выбранных особей
        new_popul = newPopul.evolve();

        Generation_Number++;

        // После определенного количества поколений, выводим наилучшее уравнение
        if (Generation_Number == MAX_GENERATIONS) {
            int bestIndividualIndex = sellist[0]; // Индекс самой приспособленной особи
            std::array<int, 4> bestCoefficients = new_popul[bestIndividualIndex].getCoefficients(); // Коэффициенты этой особи

            std::cout << "\nBest Equation after " << MAX_GENERATIONS << " Generations:\n";
            std::cout << "Cubic Equation: " << bestCoefficients[0] << "x^3 + "
                << bestCoefficients[1] << "x^2 + " << bestCoefficients[2] << "x + " << bestCoefficients[3] << " = 0" << std::endl;

            CubicEquation bestEntity(bestCoefficients);
           ;
            std::array<double, 3> bestRoots = bestEntity.solve(); // Корни уравнения
            std::cout << "Equation Roots: " << bestRoots[0] << ", " << bestRoots[1] << ", " << bestRoots[2] << std::endl;

            break; // Завершаем цикл после вывода результата
        }
    }


    return 0;
}