#include "Header.h"

// В начале игры особьи находятся по главной диоганали доски и имеют 4 здоровия 
// 1 мина отнимает 2 здоровия 

int players[10][3];   // Данные об игроках
int turn_list[10], check_list[10]; // Массивы с результатами направления действия для каждой особи
int game_board[100]; // Массив для игровой доски. В ней 2 знчения: 0 - клетка пуста, 1 - в клетке мина
int mine_number = 10; // Количество оставшихся мин 
int death_toll = 0; // Количество умерших
int min_pos[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // Позиции мин на карте
// Игровая доска. Размеры (10*10). Мины (10). 
int map_initialization() {
	
	int mine; // Для определения куда поставить мину

	// Первоначальное заполнение нулями
	for (int i = 0; i < 100; i++) {
		game_board[i] = 0;
	}

	// Выставление мин 
	int m = 0;
	while (m < 10) {
		mine = rand() % 100;
		if (mine % 11 != 0 && game_board[mine] != 1) {
			game_board[mine] = 1;
			min_pos[m] = mine;
			m++;
		}
	}

	// Вывод массива (карты мин) на консоль (для тестов)
	/*cout << "\n" << "Mine map:" << endl;
	for (int i = 1; i < 101; i++) {
		cout << game_board[i-1] << " ";
		if (i % 10 == 0) cout << endl;
	}*/
	
	return 0;
}

// Функция начального заполнения данных об особях играюших в игру.
int player_initialization() {

	// Предворительное заполнение данных об игроках
	for (int i = 0; i <10; i++) {
		players[i][0] = 4; // Первый столбец здоровие (4 пункта)
		players[i][1] = i * 11; // Второй - положение на доске
		players[i][2] = 0; // Третий - количество пройденных шагов
	}

	// Вывод сведений об игроках
	/*cout << "\n" << "Player information:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Player" << i << "  ";
		for (int j = 0; j < 3; j++) {
			cout << players[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}

// Вычисление дальнейших действий особей. Сохраняет резултаты в turn_list[10] и check_list[10]
int player_turn(int new_popul[10][8]) {
	
	int i, j, sum_turn[10], sum_check[10];
	
	// Предварительное заполнение / очиска
	for (i = 0; i < 10; i++) {
		sum_turn[i] = 0;
		sum_check[i] = 0;
		turn_list[i] = 0;
		check_list[i] = 0;

	}

	// Нахождение суммы для последуещего выбора с разными вероятностями
	for (j = 0; j < 10; j++) {

		// Для хода.
		for (i = 0; i < 4; i++) {
			sum_turn[j] += new_popul[j][i];
		}

		// Для проверки.
		for (i = 4; i < 8; i++) {
			sum_check[j] += new_popul[j][i];
		}
	}

	// Вывод массивов с сумами (для тестов)
	/*cout << "\n" << "sum:" << endl;
	cout << "   t" << "   ch" << endl;
	for (i = 0; i < 10; i++) {
		cout << i << " " << sum_turn[i] << " " << sum_check[i] << endl;
	}*/

	// Случайный выбор стороны хода и стороны проверки на мину с разными вероятноcтями

	// Выбор напрваления хода для всех особей
	for (i = 0; i < 10; i++) {

		// Случайно с разным % выподения выберается сторона 
		int fortune_turn = rand() % sum_turn[i] + 1;
		int accumulation_turn = new_popul[i][0];

		// Далее нужная сторона заносится в массив с результатами для каждой особи turn_list[10]
		if (fortune_turn <= new_popul[i][0]) {
			turn_list[i] = 0;
		}

		if (accumulation_turn + 1 <= fortune_turn && fortune_turn <= accumulation_turn + new_popul[i][1]) {
			turn_list[i] = 1;
		}
		accumulation_turn += new_popul[i][1];

		if (accumulation_turn + 1 <= fortune_turn && fortune_turn <= accumulation_turn + new_popul[i][2]) {
			turn_list[i] = 2;
		}
		accumulation_turn += new_popul[i][2];

		if (accumulation_turn + 1 <= fortune_turn && fortune_turn <= sum_turn[i]) {
			turn_list[i] = 3;
		}
	
	}

	// Выбор напрваления проверки на содержание мины для всех особей
	for (i = 0; i < 10; i++) {

		// Случайно с разным % выподения выберается сторона 
		int fortune_check = rand() % sum_check[i] + 1;
		int accumulation_check = new_popul[i][4];

		// Далее нужная сторона заносится в массив с результатами для каждой особи check_list[10]
		if (fortune_check <= new_popul[i][4]) {
			check_list[i] = 0;
		}

		if (accumulation_check + 1 <= fortune_check && fortune_check <= accumulation_check + new_popul[i][5]) {
			check_list[i] = 1;
		}
		accumulation_check += new_popul[i][5];

		if (accumulation_check + 1 <= fortune_check && fortune_check <= accumulation_check + new_popul[i][6]) {
			check_list[i] = 2;
		}
		accumulation_check += new_popul[i][6];

		if (accumulation_check + 1 <= fortune_check && fortune_check <= sum_check[i]) {
			check_list[i] = 3;
		}

	}

	// Вывод массивов с направлением действия (для тестов)
	/*cout << "\n" << "Individual actions:" << endl;
	cout << "   Turn" << "  Cheeck" << endl;
	for (i = 0; i < 10; i++) {
		cout << i << "     " << turn_list[i] << "       " << check_list[i] << endl;
	}*/

	return 0;
}

// Применение действий особей
int turn(int players[10][3], int turn_list[10], int check_list[10], int game_board[100]) {

	// Вывод нынешнего состояния доски
	cout << "\n" << "Map:" << endl;
	for (int j = 0; j < 100; j++) {  // Проходит по всем клеткам доски
		bool is_written = false; // Записано ли число?
		bool occupied = false; // Место уже занято игроком?

		// Проходит по всем минам
		for (int i = 0; i < 10; i++) {
			bool on_a_mine = false; // Игрок стоит на мине i?
			bool re_on_a_mine = false; // Мина и игрок i на одной клетке?

			// Проверка стоит ли игрок на мине i
			for (int k = 0; k < 10; k++) {
				if (min_pos[i] == players[k][1]) on_a_mine = true;
				if (players[i][1] == min_pos[k]) re_on_a_mine = true;
			}

			// 1 - мина
			if (j == min_pos[i] && on_a_mine == false) {
				cout << "1 ";
				is_written = true;
			}

			// 2 - игроки
			if (j == players[i][1] && occupied == false && re_on_a_mine == false) {
				cout << "2 ";
				occupied = true;
				is_written = true;
			}

			// 3 - игрок наступил на мину
			if (j == min_pos[i] && on_a_mine == true) {
				cout << "3 "; 
				is_written = true;
			}

			on_a_mine = false;
			re_on_a_mine = false;
		}

		if (is_written != true) cout << "0 "; // 0 - пустая клетка
		if (j % 10 == 9) cout << endl;
		is_written = false;
		occupied = false;
	}
	
	int there_is_mine[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Есть ли мина на стороне, котарая проверяется? (0 - нет/1 - да)

	// 0 - вверх (-10); 1 - вправо (+1);  2 - вниз (+10); 3 - влево (-1)
	// Проверка на мину
	for (int i = 0; i < 10; i++) {

		// 0 - вверх (-10)
		if (check_list[i] == 0) {
			if (game_board[players[i][1] - 10] == 1) {
				there_is_mine[i] = 1;
				mine_number -= 1;
			}
		}

		// 1 - вправо (+1)
		if (check_list[i] == 1) {
			if (game_board[players[i][1] + 1] == 1) {
				there_is_mine[i] = 1;
				mine_number -= 1;
			}
		}

		// 2 - вниз (+10)
		if (check_list[i] == 2) {
			if (game_board[players[i][1] + 10] == 1) {
				there_is_mine[i] = 1;
				mine_number -= 1;
			}
		}

		// 3 - влево (-1)
		if (check_list[i] == 3) {
			if (game_board[players[i][1] - 1] == 1) {
				there_is_mine[i] = 1;
				mine_number -= 1;
			}
		}
	}

	// Вывод результатв проверки (для тестов)
	/*for (int i = 0; i < 10; i++) {
		cout << i << " " << there_is_mine[i] << endl;
	}*/
	
	// Перемещение игрока по полю. 
	for (int i = 0; i < 10; i++) {
		// Если он видит, что в точке назначения мина, или идёт за границы игрового поля, он остаётся на месте.

		// 0 - вверх (-10)
		if (turn_list[i] == 0 && players[i][1] > 9) {
			if (!(there_is_mine[i] == 1 && check_list[i] == turn_list[i])) {
				players[i][1] -= 10;
			}
			players[i][2] += 1; // +1 к к-ву ходов
		}

		// 1 - вправо (+1)
		if (turn_list[i] == 1 && players[i][1] % 10 != 9) {
			if (!(there_is_mine[i] == 1 && check_list[i] == turn_list[i])) {
				players[i][1] += 1;
			}
			players[i][2] += 1; // +1 к к-ву ходов
		}

		// 2 - вниз (+10)
		if (turn_list[i] == 2 && players[i][1] < 90) {
			if (!(there_is_mine[i] == 1 && check_list[i] == turn_list[i])) {
				players[i][1] += 10;
			}
			players[i][2] += 1; // +1 к к-ву ходов
		}

		// 3 - влево (-1)
		if (turn_list[i] == 3 && players[i][1] % 10 != 0) {
			if (!(there_is_mine[i] == 1 && check_list[i] == turn_list[i])) {
				players[i][1] -= 1;
			}
			players[i][2] += 1; // +1 к к-ву ходов
		}
	}

	// Последствия попадения на мину.
	for (int i = 0; i < 10; i++) {
		if (game_board[players[i][1]] == 1) {
			mine_number -= 1; // Уменьшаем значение счетчика активных мин 
			players[i][0] -= 2; // Отнимаем жизни
			game_board[players[i][1]] = 0; // Удаляем мину с поля

			// Если жизни кончились то игрок перемещается в мнимую точку - 1
			if (players[i][0] <= 0) {
				players[i][1] = -1;
				death_toll += 1;
			}
		}
	}

	// Если мины кончились, то выжившие игроки возвращаютя на начальные позиции
	if (mine_number == 0) {
		for (int i = 0; i < 10; i++) {
			if (players[i][1] != -1) {
				players[i][1] == i * 11;
			}
		}
	}

	return 0;
}

// Основной игровой процесс
int game() {

	map_initialization();
	player_initialization();

	while (death_toll < 10) {
		if (mine_number == 0)  map_initialization();
		player_turn(new_popul);
		turn(players, turn_list, check_list, game_board);
	}

	return 0;
}