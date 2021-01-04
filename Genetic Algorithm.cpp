#include "Header.h"

int Generation_Number = 1; // Подчёт поколений.
int sellist[4];  // Массив с индексами четырёх наиболее приспособленных

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

// Рассчет приспособленности особей
int selection(int players[10][3]) {

	int i;
	int sum = 0; // Хранит сумму всех ходов (значений players[i][2])
	int fitness[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };; // Приспособленнось каждой особи

	// Нахожение суммы ходов
	for (i = 0; i < 10; i++) {
		sum += players[i][2];
	}

	int accumulation = players[0][2];
	int winning_individual; // Ососбь выигравшая отбор.
	int winner = 0; // Количество выигравшийих особей

	while (winner != 4) {
		int fortune = rand() % sum + 1; // Выпадение случайного отбора 

		if (fortune <= players[0][2]) {
			winning_individual = 0;
		}
		else {
			for (i = 1; i < 9; i++) {
				if (accumulation + 1 <= fortune && fortune <= accumulation + players[i][2]) {
					winning_individual = i;
				}
				accumulation += players[i][2];
			}
			if (accumulation + 1 <= fortune && fortune <= 10000) {
				winning_individual = 9;
			}
		}
		sellist[winner] = winning_individual;
		accumulation = players[0][2];
		winner += 1;
	}

	return 0;
}