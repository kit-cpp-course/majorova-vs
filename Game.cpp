#include "Game.h"


Game::Game()
{
	t1.loadFromFile("images/doodle.png");
	t2.loadFromFile("images/utenok.png");
	t3.loadFromFile("images/background.png");
	t4.loadFromFile("images/platform.png");

	pl = new Player(&t1, "Name", 300, 300);
	for (int i = 0; i < 10; i++)
	{
		ent.push_back(new Platforms(&t4, "Platforma", std::rand() % 400, std::rand() % 533, 68.0f, 14.0f));
	}

	for (int i = 0; i < 2; i++)
	{
		ent.push_back(new Enemy(&t2, "EasyEnemy", 0.0f, rand() % 533));
		ent.push_back(new Enemy(&t2, "EasyEnemy2", 400.0f, 100.0f));
	}
}

Game::~Game()
{
	delete pl;
	for (it = ent.begin(); it != ent.end(); it++)
	{
		delete *it;
	}
}

void Game::Collision()
{
	for (it = ent.begin(); it != ent.end(); it++)
	{
		if ((pl->body.getPosition().x + 50 > (*it)->body.getPosition().x) && (pl->body.getPosition().x + 20 < (*it)->body.getPosition().x + 68)
			&& (pl->body.getPosition().y + 70 > (*it)->body.getPosition().y) && (pl->body.getPosition().y + 70 < (*it)->body.getPosition().y + 14) && (pl->dy > 0))
		{
			if ((*it)->name == "EasyEnemy" || (*it)->name == "EasyEnemy2") //Если предмет в списке - это враг,
			{                                                              //то он исчезает и появляется со случайной координатой.   
				(*it)->body.setPosition(rand() % 400, rand() % 533);
				
			}
			pl->dy = -10;
		}
	}
}

void Game::Move()
{
	for (it = ent.begin(); it != ent.end(); it++)
	{
		(*it)->Move();
	}

	if (pl->body.getPosition().y < pl->h)
	{
		for (it = ent.begin(); it != ent.end(); it++) 
		{
			pl->body.setPosition({ pl->body.getPosition().x, pl->h }); // Координата У игрока установлена на 200

			(*it)->body.setPosition({ (*it)->body.getPosition().x, (*it)->body.getPosition().y - pl->dy }); // Все платформы и монстры смещаются по оси ординат на dy
			
					// Когда платформа(или монстр) оказывается на нижней части экрана, она перерисовывается
					// на верхней части экрана со случайной координатой х.
			if ((*it)->body.getPosition().y > 533) 
			{
				(*it)->body.setPosition((*it)->body.getPosition().x, 0.0f);
				(*it)->body.setPosition((std::rand() % 400), (*it)->body.getPosition().y);

			}
		}
	}
	pl->Move();
}

void Game::BackgroundDraw(sf::RenderWindow & window)
{
	background.setSize(sf::Vector2f(400.0f, 533.0f));
	background.setTexture(&t3);
	window.draw(background);
	for (it = ent.begin(); it != ent.end(); it++)
	{
		(*it)->Draw(window);
	}
	pl->Draw(window);
}

void Game::GamePr(sf::RenderWindow & window)
{
	BackgroundDraw(window);
	Collision();
	Move();
}






