#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Platforms.h"
#include "Constants.h"
#include <iostream>
#include <list>

using namespace sf;

int main()
{
	Texture t1;
	t1.loadFromFile("images/doodle.png");
	Player pl(&t1, "Player", 200, 200);
	std::list<Entity*> ent;
	std::list<Entity*>::iterator it;
	Game game(ent);

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
		game.GamePr(pl, ent, it, window);
		window.display();
	}
	return 0;
}

