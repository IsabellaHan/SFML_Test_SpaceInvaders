#include "enemy.h"



enemy::enemy()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Blue);
	sprite.setScale(0.1, 0.1);

	/*elapsed = clock.getElapsedTime();*/
	//sprite.setTextureRect(sf::IntRect(49 * 4, 0, 49, 49));
}

void enemy::update()
{
	sprite.setPosition(rect.getPosition());
	loc = rect.getPosition();
}

void enemy::updateMovement()
{

	rect.move(speed, 0);

	walkCounter++;
	if (walkCounter == 1)
		walkCounter = 0;

	
}



