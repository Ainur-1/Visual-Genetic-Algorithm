#pragma once
#ifndef Header
#define Header

#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;
extern int new_popul[10][8]; // ������ ����� ���������. 
extern int players[10][3];   // ������ �� �������


int initial_population(); // ������� ���������� ��������� ��������� �� ���������� ������
int game();
int demo();

#endif
