#include <iostream>
#include <cstdlib>
#include <cmath>

int Generation_Number = 1;
int sellist[4];
int new_popul[10][4]; // Изменили размер массива для хранения коэффициентов

// Генерация начальной популяции с случайными коэффициентами
int initial_population() {
    std::cout << "New Genetic Algorithm for Cubic Equation\n\n";
    int i, j;

    std::cout << "\nGeneration " << Generation_Number << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";
    for (i = 0; i < 10; i++) {
        std::cout << "Individual " << i << "   ";
        for (j = 0; j < 4; j++) {
            new_popul[i][j] = rand() % 101;
            if (new_popul[i][j] == 100)
                std::cout << new_popul[i][j] << " ";
            if (new_popul[i][j] < 10)
                std::cout << "  " << new_popul[i][j] << " ";
            if (new_popul[i][j] > 9 && new_popul[i][j] < 100)
                std::cout << " " << new_popul[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

// Оценка приспособленности особей (в данном случае - близость к корню)
double fitness_evaluation(double coefficients[10][4], double target_root) {
    double fitness[10];
    for (int i = 0; i < 10; i++) {
        double result = coefficients[i][0] + coefficients[i][1] * target_root +
            coefficients[i][2] * target_root * target_root +
            coefficients[i][3] * target_root * target_root * target_root;
        fitness[i] = 1.0 / std::abs(result - target_root);
    }
    // Здесь можно также нормализовать приспособленность, чтобы сумма была 1.
    return fitness;
}

// Выбор особей для следующего поколения
void selection(double coefficients[10][4]) {
    // Здесь реализация выбора особей для создания следующего поколения
    // Можно использовать методы селекции, такие как рулеточное колесо или турнирная селекция.
    // sellist будет хранить индексы выбранных особей.
}

int main() {
    srand(time(NULL));

    double target_root = 3.0; // Корень, который мы хотим найти
    double coefficients[10][4]; // Коэффициенты кубического уравнения

    initial_population();

    // Основной цикл генетического алгоритма
    while (/*условие остановки*/) {
        // Оценка приспособленности
        double fitness_values[10];
        fitness_values = fitness_evaluation(coefficients, target_root);

        // Выбор особей для следующего поколения
        selection(coefficients);

        // Создание новой популяции на основе выбранных особей
        // Мутация и скрещивание могут быть реализованы здесь

        Generation_Number++;
    }

    // Вывод результирующего уравнения
    // Здесь можно взять лучший набор коэффициентов и вывести полученное уравнение

    return 0;
}
