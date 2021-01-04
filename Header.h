#pragma once
#ifndef Header
#define Header

#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;
extern int new_popul[10][8]; // Массив новой популяции. 
extern int players[10][3];   // Данные об игроках


int initial_population(); // Функция генерирует начальную популяцию со случайными генами
int game();
int demo();

#endif
