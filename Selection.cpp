#include "Selection.h"
#include "Entity.h"

Selection::Selection(std::array<Entity, 10>& population, std::array<double, 10> fitness) {
	fitness_ = fitness;
	oldPopul = population;

}

// ¬ыбор особей дл€ следующего поколени€
std::array<int, 5> Selection::select() {
    std::array<int, 5> sellist;

    for (int i = 0; i < 5; i++) {
        int maxIndex = 0;
        double maxFitness = -1.0;

        for (int j = 0; j < 10; j++) {
            if (fitness_[j] > maxFitness) {
                bool isAlreadySelected = false;
                for (int k = 0; k < i; k++) {
                    if (sellist[k] == j) {
                        isAlreadySelected = true;
                        break;
                    }
                }

                if (!isAlreadySelected) {
                    maxIndex = j;
                    maxFitness = fitness_[j];
                }
            }
        }

        sellist[i] = maxIndex;
    }

    return sellist;
}