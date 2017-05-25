#include "bullet.h"



bullet::bullet()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Green);
}

void bullet::update()
{
	rect.move(0, -bulletSpeed);
	lifetimeCounter++;
	if (lifetimeCounter >= lifetime)
	{
		destroy = true;
	}
}



