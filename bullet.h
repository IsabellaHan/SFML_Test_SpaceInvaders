#pragma once
#include "BaseUnit.h"
class bullet:public BaseUnit
{
public:
	bullet();
	
	int bulletSpeed = 10;
	int attackDamage = 1;
	int lifetimeCounter = 0;
	int lifetime = 60;
	bool destroy = false;

	void update();
};

