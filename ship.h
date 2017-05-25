#pragma once
#include "BaseUnit.h"
class ship:public BaseUnit
{
public:
	ship();
	int health = 10;
	int score = 0;
	int walkingCounter = 0;
	float playerSpeed = 0.1;
	int attackDamage = 5;

	void update();
	void updateMovement();
};

