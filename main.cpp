#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

void printFormattedNumber(int num) {
    if (num == 100)
        std::cout << num << " ";
    else if (num < 10)
        std::cout << "  " << num << " ";
    else if (num >= 10 && num < 100)
        std::cout << " " << num << " ";
}

void printPopulation(std::array<std::array<int, 4>, 10> new_popul) {
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

//// Оценка приспособленности особей (в данном случае - близость к корню)
//double fitness_evaluation(double coefficients[10][4], double target_root) {
//    double fitness[10];
//    for (int i = 0; i < 10; i++) {
//        double result = coefficients[i][0] + coefficients[i][1] * target_root +
//            coefficients[i][2] * target_root * target_root +
//            coefficients[i][3] * target_root * target_root * target_root;
//        fitness[i] = 1.0 / std::abs(result - target_root);
//    }
//    // Здесь можно также нормализовать приспособленность, чтобы сумма была 1.
//    return fitness;
//}
//
//// Выбор особей для следующего поколения
//void selection(double coefficients[10][4]) {
//    // Здесь реализация выбора особей для создания следующего поколения
//    // Можно использовать методы селекции, такие как рулеточное колесо или турнирная селекция.
//    // sellist будет хранить индексы выбранных особей.
//}

int main() {
    srand(time(NULL));
    
    int Generation_Number = 1;
    int sellist[4];

    std::cout << "New Genetic Algorithm for Cubic Equation\n\n";
    std::cout << "\nGeneration " << Generation_Number << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";

    std::array<std::array<int, 4>, 10> new_popul = initial_population();

    printPopulation(new_popul);

    double target_root = 3.0; // Корень, который мы хотим найти
    double coefficients[10][4]; // Коэффициенты кубического уравнения

    //// Основной цикл генетического алгоритма
    //while (/*условие остановки*/) {
    //    // Оценка приспособленности
    //    double fitness_values[10];
    //    fitness_values = fitness_evaluation(coefficients, target_root);

    //    // Выбор особей для следующего поколения
    //    selection(coefficients);

    //    // Создание новой популяции на основе выбранных особей
    //    // Мутация и скрещивание могут быть реализованы здесь

    //    Generation_Number++;
    //}

    // Вывод результирующего уравнения
    // Здесь можно взять лучший набор коэффициентов и вывести полученное уравнение

    return 0;
}
