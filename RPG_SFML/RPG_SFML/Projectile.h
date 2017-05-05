#pragma once
#include "Entity.h"
class Projectile : public Entity
{
public:
	float playerSpeed = 0.2;
	int attackDamage = 5;
	int walkingCounter = 0;

	Projectile();
	//void update();
	//void updateMovement();
};

