#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Constants.h"
#include "Entity.h"
#include "Platforms.h"
#include "Player.h"
#include "Enemy.h"

using namespace sf;

class Game {
public:
	/*
	 * Конструктор, заполняющий список ent предметами, которые будут появляться в игре много раз
	 * @param ent список, включающий в себя все предметы
	 */
	Game(std::list<Entity*> &ent) {

		t2.loadFromFile("images/utenok.png");
		t3.loadFromFile("images/background.png");
		t4.loadFromFile("images/platform.png");

		for (int i = 0; i < 10; i++)
		{
			ent.push_back(new Platforms(&t4, "Platforma", std::rand() % 400, std::rand() % 533, w, hh));
		}

		for (int i = 0; i < 2; i++)
		{
			ent.push_back(new Enemy(&t2, "EasyEnemy", 0, rand() % 533));
			ent.push_back(new Enemy(&t2, "EasyEnemy2", 400, 100));
		}
		
	}

	/*
	 * Обрабатывает столкновение игрока с предметами
	 * @param pl игрок
	 * @param ent список всех предметов, которые появятся в игре много раз
	 * @param it итератор для обхода по списку
	 */

	void Collision(Player &pl, std::list<Entity*> &ent, std::list<Entity*>::iterator &it) {
		
		for (it = ent.begin(); it != ent.end(); it++)
		{
			if ((pl.body.getPosition().x + 50 > (*it)->body.getPosition().x) && (pl.body.getPosition().x + 20 < (*it)->body.getPosition().x + 68)
				&& (pl.body.getPosition().y + 70 > (*it)->body.getPosition().y) && (pl.body.getPosition().y + 70 < (*it)->body.getPosition().y + 14) && (pl.dy > 0)) {
				if ((*it)->name == "EasyEnemy" || (*it)->name == "EasyEnemy2") { //Если предмет в списке - это враг, то он уничтожается
					(*it)->body.setPosition(1000, 1000);
				}
				pl.dy = -10;
			}
		}

	}

	/*
	 * Отвечает за прокрутку экрана и перемещение платформ по мере движения игрока наверх
	 * @param pl игрок
	 * @param ent список всех предметов, которые появятся в игре много раз
	 * @param it итератор для обхода по списку
	 */

	void Move(Player &pl, std::list<Entity*> &ent, std::list<Entity*>::iterator &it) {

		for (it = ent.begin(); it != ent.end(); it++)
		{
			(*it)->Move();
		}

		if (pl.body.getPosition().y < pl.h)
		{
			for (it = ent.begin(); it != ent.end(); it++) {
				pl.body.setPosition({ pl.body.getPosition().x, pl.h }); // Координата У игрока установлена на 200

				(*it)->body.setPosition({ (*it)->body.getPosition().x, (*it)->body.getPosition().y - pl.dy }); // Все платформы смещаются по оси ординат на dy

						// Когда платформа оказывается на нижней части экрана, она перерисовывается
						// на верхней части экрана со случайной координатой х.
				if ((*it)->body.getPosition().y > 533) {
					(*it)->body.setPosition((*it)->body.getPosition().x, 0.0f);
					(*it)->body.setPosition((std::rand() % 400), (*it)->body.getPosition().y);

				}
			}
		}
		pl.Move();

	}

	/*
	 * Отвечает за рисование игрока и всех предметов в окне
	 * @param pl игрок
	 * @param ent список всех предметов, которые появятся в игре много раз
	 * @param it итератор для обхода по списку
	 * @param window окно, где происходит действие
	 */

	void BackgroundDraw(Player &pl, std::list<Entity*> &ent, std::list<Entity*>::iterator &it, sf::RenderWindow & window) {
		background.setSize(sf::Vector2f(400.0f, 533.0f));
		background.setTexture(&t3);
		window.draw(background);
		for (it = ent.begin(); it != ent.end(); it++)
		{
			(*it)->Draw(window);
		}
		pl.Draw(window);
	}

	/*
	 * Процесс игры. Вызывается функция рисования, передвижения, обрабатываются столкновения.
	 * @param pl игрок
	 * @param ent список всех предметов, которые появятся в игре много раз
	 * @param it итератор для обхода по списку
	 * @param window окно, где происходит действие
	 */

	void GamePr(Player &pl, std::list<Entity*> &ent, std::list<Entity*>::iterator &it, sf::RenderWindow & window) {
		BackgroundDraw(pl, ent, it, window);
		Collision(pl, ent, it);
		Move(pl, ent, it);
	}

	
private:
	Texture t2;
	Texture t3;
	Texture t4;
	RectangleShape background;
};