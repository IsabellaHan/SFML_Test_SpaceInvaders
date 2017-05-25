#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ship.h"
#include "bullet.h"
#include "enemy.h"

int main()
{
	Clock clock;
	Clock clock2;
	Clock clock3;

	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;



	sf::RenderWindow window(sf::VideoMode(900, 600), "SFML works!");
	sf::Texture textPlayer;
	if (!textPlayer.loadFromFile("ship.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Texture textEnemy;
	if (!textEnemy.loadFromFile("enemy.png"))
	{
		return EXIT_FAILURE;
	}

	class ship player;
	player.sprite.setTexture(textPlayer);

	//ENEMY
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;
	class enemy enemy;
	enemy.sprite.setTexture(textEnemy);
	enemy.rect.setPosition(100, 100);
	enemyArray.push_back(enemy);

	int i;
	int enemyAmount = 6;

	for (i = 0; i < enemyAmount; i++)
	{

		enemy.rect.setPosition(enemyArray[i].rect.getPosition().x + 50, 100);
		enemyArray.push_back(enemy);
	}
	for (i = 0; i < enemyAmount-1; i++)
	{

		enemy.rect.setPosition(enemyArray[i].rect.getPosition().x + 50, 170);
		enemyArray.push_back(enemy);
	}


	vector<bullet>::const_iterator iter; 
	vector<bullet> projectileArray;
	class bullet projectile;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}
		


		window.clear();

		
		Time elapsed1 = clock.getElapsedTime();
		Time elapsed2 = clock2.getElapsedTime();

		// shoot bullets
		if (elapsed1.asMilliseconds() >= 15)
		{				
			clock.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					projectile.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2, player.rect.getPosition().y + (player.rect.getSize().y) / 2);
					projectileArray.push_back(projectile); // push into array
				}
		}

		// destroying enemies
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					projectileArray[counter].destroy = true;
					enemyArray[counter2].alive = false;

				}
				counter2++;
			}
			counter++;
		}

			// delete bullets
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
			if (projectileArray[counter].destroy == true)
			{
				projectileArray.erase(iter);
				break;
			}
			counter++;
		}
		// draw bullets
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			projectileArray[counter].update(); // Update Projectile
			window.draw(projectileArray[counter].rect);

			counter++;
		}

		// draw enemy
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			enemyArray[counter].update();
			enemyArray[counter].updateMovement();
			window.draw(enemyArray[counter].sprite);

			if (elapsed2.asSeconds() >= enemyArray[counter].turnTime)
			{
				enemyArray[counter].speed *= -1;
				enemyArray[counter].rect.setPosition(enemyArray[counter].rect.getPosition().x, enemyArray[counter].rect.getPosition().y+50);
				clock2.restart();
			}
			counter++;

		}

		

		player.update();
		player.updateMovement();
		window.draw(player.sprite);

		sf::Vector2f local = player.rect.getPosition();
		if (local.x > window.getSize().x)
		{
			player.rect.setPosition(0, local.y);
		}
		if (local.x < 0)
		{
			player.rect.setPosition(window.getSize().x, local.y);
		}

		// destroy enemies if they are out of screen
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {

			if (enemyArray[counter].rect.getPosition().y > window.getSize().y || enemyArray[counter].alive == false)
			{
				enemyArray.erase(iter4);
				
				break;
			}
			counter++;
		}

	

		window.display();
	}
	

	return 0;
}