#pragma once
#ifndef Header
#define Header

#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;
extern int new_popul[10][8]; // ћассив новой попул€ции. 

int initial_population(); // ‘ункци€ генерирует начальную попул€цию со случайными генами
int game();
int demo();

#endif
