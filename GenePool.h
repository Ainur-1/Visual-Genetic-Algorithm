#pragma once

#include <array>

class GenePool {
public:
    GenePool(); // Конструктор
    ~GenePool(); // Деструктор

    void initialize(); // Инициализация начальной популяции
    void evolve(int maxGenerations); // Запуск генетического алгоритма

private:
    // Здесь вы можете добавить приватные методы и члены класса, если необходимо
};
