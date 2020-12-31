#include "Header.h"

int Generation_Number = 1; // Подчёт поколений.

// Массив новой популяции. 
// Каждая особь состоит из 8 генов: [a][b][c][d]. Для хода и для проверки клетки
// [a] - вверх, [b] - вниз, [c] - вправо, [d] - влево
int new_popul[10][8]; 

// Функция генерирует начальную популяцию со случайными генами
int initial_population() {

	// Особь состоит из 8 генов, в популяции 10 особей.
	cout << "New Genetic Algorithm " << "\n" << endl;

	int i, j;

	// Создаем начальную популяцию.
	cout << "\n" << "Generation " << Generation_Number << endl;
	cout << "                      Move           Check" << "\n";
	cout << " Chromosome " << "     a   b   c   d " << "   a   b   c   d " << "\n" << "\n";
	for (i = 0; i < 10; i++) {

		cout << "Individual " << i << "   ";

		for (j = 0; j < 8; j++) {

			new_popul[i][j] = rand() % 101;

			if (new_popul[i][j] == 100)
				cout << new_popul[i][j] << " ";

			if (new_popul[i][j] < 10)
				cout << "  " << new_popul[i][j] << " ";

			if (new_popul[i][j] > 9 && new_popul[i][j] < 100)
				cout << " " << new_popul[i][j] << " ";

			if (j == 3)
				cout << '|';
		}

		cout << endl;
	}

	return 0;
}