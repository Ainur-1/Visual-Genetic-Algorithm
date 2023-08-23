#pragma once

#include "Entity.h"
#include <array>

class Selection
{
public:
	Selection(std::array<Entity, 10>& population, std::array<double, 10> fitness);

	std::array<int, 5> select();

private:
	std::array<double, 10> fitness_;
	std::array<Entity, 10> oldPopul;
	std::array<Entity, 10> newPopul;
};

