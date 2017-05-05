#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "ResourcePath.hpp"
#include "Entity.h"
#include "Player.h"
#include "Projectile.h"


int main()
{
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;
	
	// class RenderWindow made window
	//sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::RenderWindow window(sf::VideoMode(1000, 800), "MY window", sf::Style::Resize);


	sf::Texture textPlayer;
	if (!textPlayer.loadFromFile("SpriteWalk.png"))
	{
		return EXIT_FAILURE;
	}

	sf::Sprite spritePlayer(textPlayer);
	spritePlayer.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	spritePlayer.setTextureRect(sf::IntRect(10, 10, 100, 140)); // cut the sprite sheet

	class Player player;
	player.sprite.setTexture(textPlayer);

	// Projectile Vector Array
	vector<Projectile>::const_iterator iter; // iterator: references where we are in array
	vector<Projectile> projectileArray; // hold only projectile array
	// projectile object
	class Projectile projectile;


	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}
		window.clear();

		// shoot!!
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			projectile.rect.setPosition(player.rect.getPosition());
			projectileArray.push_back(projectile); // push into array
		}

		// draw projectile
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			window.draw(projectileArray[counter].rect);

			counter++;
		}

		player.update();
		player.updateMovement();

		window.draw(player.sprite);

		window.display();
	}
	
	

	return 0;
}

//void CheckSFML()
//{
//	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//}