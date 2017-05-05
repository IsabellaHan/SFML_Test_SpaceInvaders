#include "Player.h"

Player::Player() {
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);

	//sprite.setPosition(400, 200);

	sprite.setTextureRect(sf::IntRect(10, 10, 100, 140)); // cut the sprite sheet


	//rect is used to player collision
}

void Player::update() {
	sprite.setPosition(rect.getPosition());
}

void Player::updateMovement() {
	// (0,0) top left 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rect.move(playerSpeed, 0);
		sprite.setTextureRect(sf::IntRect(130 * walkingCounter, 250, 100, 140));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		rect.move(0, -playerSpeed);
		sprite.setTextureRect(sf::IntRect(130 * walkingCounter, 400, 100, 140)); // cut the sprite sheet

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		rect.move(0, playerSpeed);
		sprite.setTextureRect(sf::IntRect(130 * walkingCounter, 10, 100, 140));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rect.move(-playerSpeed, 0);
		sprite.setTextureRect(sf::IntRect(130 * walkingCounter, 125, 100, 140));
	}

	walkingCounter++;
	if (walkingCounter == 3)
		walkingCounter = 0;
}




