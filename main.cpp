#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "CubicEquation.h"
#include "Entity.h"
#include "Population.h"

// Выбор особей для следующего поколения
std::array<int, 5> selection(const std::array<double, 10>& fitness) {
    std::array<int, 5> sellist;

    for (int i = 0; i < 5; i++) {
        int maxIndex = 0;
        double maxFitness = -1.0;

        for (int j = 0; j < 10; j++) {
            if (fitness[j] > maxFitness) {
                bool isAlreadySelected = false;
                for (int k = 0; k < i; k++) {
                    if (sellist[k] == j) {
                        isAlreadySelected = true;
                        break;
                    }
                }

                if (!isAlreadySelected) {
                    maxIndex = j;
                    maxFitness = fitness[j];
                }
            }
        }

        sellist[i] = maxIndex;
    }

    return sellist;
}

// Создание новой популяции на основе выбранных особей
std::array<Entity, 10> createNewPopulation(const std::array<Entity, 10>& old_popul, const std::array<int, 5>& sellist) {
    std::array<Entity, 10> new_popul;

    // Копирование выбранных особей в новую популяцию
    for (int i = 0; i < 5; i++) {
        new_popul[i] = old_popul[sellist[i]];
    }

    // Генерация новых особей (потомков) через скрещивание
    for (int i = 5; i < 10; i++) {
        new_popul[i] = Entity::Entity();
    }

    return new_popul;
}


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
        std::array<double, 10> fitness_values = newPopul.calculateFitness(roots);

        // Выбор особей для следующего поколения
        sellist = selection(fitness_values);
        
        /*По логике будет 5 прислпособленнейших и генерироваться 5 новых.
    Также мутация будет менят некоторыхе хромосомы в некоторых особях, которое будет выбираться рандомом.*/

        // Создание новой популяции на основе выбранных особей
        new_popul = createNewPopulation(new_popul, sellist);

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