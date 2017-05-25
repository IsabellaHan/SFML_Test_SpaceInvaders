#pragma once
#include "BaseUnit.h"
using namespace sf;
class enemy:public BaseUnit
{
public:
	float speed = 0.035;
		
	bool alive = true;
	int movementLength = 100;
	int damage = 2;
	int walkCounter = 0;

	float turnTime = 3;

	Vector2f loc;

	enemy();
	

	void update();
	void updateMovement();

};

