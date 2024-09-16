#include "../include/Population.h"
#include "../include/Entity.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// ������������
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

// ����� ��� ������� ������������� ���������
std::array<Entity, 10> Population::evolve() {
    std::array<Entity, 10> new_popul;

    // ����������� ��������� ������ � ����� ���������
    for (int i = 0; i < 5; i++) {
        new_popul[i] = population_[sellist[i]];
    }

    // ��������� ����� ������ (��������) ����� �����������
    for (int i = 5; i < 10; i++) {
        new_popul[i] = Entity::Entity();
    }
    
    for (int i = 0; i < 10; i++) {
        population_[i] = new_popul[i];
    }

    return population_;
}

// ������ ����������������� ������ (�������� � ������)
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

// ����� ������ ��� ���������� ���������
std::array<int, 5> Population::selection() {
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

// ����� ������� ���������
void Population::printPopulation() {

    std::cout << "\nGeneration " << generationNumber << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";

    for (int i = 0; i < 10; i++) {
        std::cout << "Individual " << i << "   ";
        population_[i].printEntity();
        std::cout << std::endl;
    }
}