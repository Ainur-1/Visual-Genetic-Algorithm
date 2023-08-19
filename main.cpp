#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Вывод числа в формате с отступами
void printFormattedNumber(int num) {
    if (num == 100)
        std::cout << num << " ";
    else if (num < 10)
        std::cout << "  " << num << " ";
    else if (num >= 10 && num < 100)
        std::cout << " " << num << " ";
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

// Генерация начальной популяции с случайными коэффициентами
std::array<std::array<int, 4>, 10> initial_population() {
    std::array<std::array<int, 4>, 10> new_popul;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            new_popul[i][j] = rand() % 101;
        }
    }

    return new_popul;
}

// Решение кубического уравнения
std::array<double, 3> solveCubicEquation(const std::array<int, 4>& coefficients) {
    double a = coefficients[0];
    double b = coefficients[1];
    double c = coefficients[2];
    double d = coefficients[3];

    // Calculate discriminants and intermediate values
    double discriminant = 18 * a * b * c * d - 4 * b * b * b * d + b * b * c * c - 4 * a * c * c * c - 27 * a * a * d * d;
    double delta0 = b * b - 3 * a * c;
    double delta1 = 2 * b * b * b - 9 * a * b * c + 27 * a * a * d;

    // Calculate roots
    std::array<double, 3> roots;

    if (discriminant > 0) {
        double C = cbrt((delta1 + sqrt(discriminant)) / 2.0);
        double D = cbrt((delta1 - sqrt(discriminant)) / 2.0);
        roots[0] = (-b + C + D) / (3 * a);
    }
    else if (discriminant == 0) {
        roots[0] = -b / (3 * a);
    }
    else {
        double phi = acos(delta1 / (2 * sqrt(-delta0 * delta0 * delta0)));
        double magnitude = 2 * sqrt(-delta0);
        const double pi = 3.14159265358979323846; // Число π
        roots[0] = magnitude * cos(phi / 3) - b / (3 * a);
        roots[1] = magnitude * cos((phi + 2 * pi) / 3) - b / (3 * a);
        roots[2] = magnitude * cos((phi + 4 * pi) / 3) - b / (3 * a);
    }

    return roots;
}

// Оценка приспособленности особей (близость к корням)
std::array<double, 10> fitness_evaluation(const std::array<std::array<int, 4>, 10>& population,
    const std::array<double, 3>& target_roots) {
    std::array<double, 10> fitness;

    for (int i = 0; i < 10; i++) {
        double total_distance = 0.0;

        for (int j = 0; j < 3; j++) {
            std::array<double, 3> roots = solveCubicEquation(population[i]);
            for (int k = 0; k < 3; k++) {
                double distance = std::abs(roots[k] - target_roots[j]);
                total_distance += distance;
            }
        }

        fitness[i] = 1.0 / total_distance;
    }

    return fitness;
}

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
std::array<std::array<int, 4>, 10> createNewPopulation(const std::array<std::array<int, 4>, 10>& old_popul, const std::array<int, 5>& sellist) {
    std::array<std::array<int, 4>, 10> new_popul;

    // Копирование выбранных особей в новую популяцию
    for (int i = 0; i < 5; i++) {
        new_popul[i] = old_popul[sellist[i]];
    }

    // Генерация новых особей (потомков) через скрещивание
    for (int i = 5; i < 10; i++) {
        int parent1Index = rand() % 5; // Выбор случайного родителя из выбранных особей
        int parent2Index = rand() % 5; // Выбор еще одного случайного родителя из выбранных особей

        // Производим скрещивание (можно использовать простое скрещивание с одной точкой)
        int crossoverPoint = rand() % 4; // Выбор случайной точки скрещивания

        for (int j = 0; j < 4; j++) {
            if (j < crossoverPoint) {
                new_popul[i][j] = old_popul[sellist[parent1Index]][j];
            }
            else {
                new_popul[i][j] = old_popul[sellist[parent2Index]][j];
            }
        }

        // Производим мутацию
        int mutationGeneIndex = rand() % 4; // Выбор случайного гена для мутации
        new_popul[i][mutationGeneIndex] = rand() % 101; // Мутируем ген случайным значением
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

    std::array<double, 3> roots = solveCubicEquation(coefficients); // Корни кубического уравнения


    std::cout << std::endl << "Cubic Equation: " << coefficients[0] << "x^3 + "
        << coefficients[1] << "x^2 + " << coefficients[2] << "x + " << coefficients[3] << " = 0" << std::endl;

    std::cout << "Equation Roots: " << roots[0] << ", " << roots[1] << ", " << roots[2] << std::endl;

    int Generation_Number = 1;
    std::array<int, 5> sellist; // Массив наиболее приспособленных.

    std::array<std::array<int, 4>, 10> new_popul = initial_population();
    printPopulation(Generation_Number, new_popul);

    // Основной цикл генетического алгоритма
    while (true) {
        // Оценка приспособленности
        std::array<double, 10> fitness_values = fitness_evaluation(new_popul, roots);

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
            std::array<int, 4> bestCoefficients = new_popul[bestIndividualIndex]; // Коэффициенты этой особи

            std::cout << "\nBest Equation after " << MAX_GENERATIONS << " Generations:\n";
            std::cout << "Cubic Equation: " << bestCoefficients[0] << "x^3 + "
                << bestCoefficients[1] << "x^2 + " << bestCoefficients[2] << "x + " << bestCoefficients[3] << " = 0" << std::endl;

            std::array<double, 3> bestRoots = solveCubicEquation(bestCoefficients); // Корни уравнения
            std::cout << "Equation Roots: " << bestRoots[0] << ", " << bestRoots[1] << ", " << bestRoots[2] << std::endl;

            break; // Завершаем цикл после вывода результата
        }
    }


    return 0;
}