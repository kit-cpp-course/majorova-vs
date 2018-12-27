#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Platforms.h"
#include <iostream>
#include <list>

using namespace sf;

int main()
{
	Game game;
	RenderWindow window(VideoMode(400, 533), "Doodle Game");
	window.setFramerateLimit(80);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		game.GamePr(window);
		window.display();
	}
	return 0;
}

