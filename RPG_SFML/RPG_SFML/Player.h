#pragma once

#include "Entity.h"

#ifndef __InstallingSFML__player__
#define __InstallingSFML__player__

class Player: public Entity
{
public:
	float playerSpeed = 0.2;
	int attackDamage = 5;
	int walkingCounter = 0;

	Player();
	void update();
	void updateMovement();
};

#endif /* defined(__InstallingSFML__player__) */