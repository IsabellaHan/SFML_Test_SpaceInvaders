#include "ship.h"



ship::ship()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(550, 550);
	rect.setFillColor(sf::Color::Blue);
	sprite.setScale(0.5, 0.5);
}

void ship::update()
{
	sprite.setPosition(rect.getPosition());
}

void ship::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rect.move(playerSpeed, 0);
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rect.move(-playerSpeed, 0);
	}

	walkingCounter++;
	if (walkingCounter == 3)
		walkingCounter = 0;
}



