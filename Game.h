#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Entity.h"
#include "Platforms.h"
#include "Player.h"
#include "Enemy.h"


using namespace sf;

class Game {
public:
	/*
	 * Конструктор, заполняющий список ent предметами, которые будут появляться в игре много раз.
	 */
	
	Game();

	/*
	 * Деструктор
	 */

	~Game();

	/*
	 * Обрабатывает столкновение игрока с предметами
	 */

	void Collision();

	/*
	 * Отвечает за прокрутку экрана и перемещение платформ по мере движения игрока наверх
	 */

	void Move();

	/*
	 * Отвечает за рисование игрока и всех предметов в окне
	 * @param window окно, где происходит действие
	 */

	void BackgroundDraw(sf::RenderWindow & window);

	/*
	 * Процесс игры. Вызывается функция рисования, передвижения, обрабатываются столкновения.
	 * @param window окно, где происходит действие
	 */

	void GamePr(sf::RenderWindow & window);

	
private:
	Texture t1;
	Texture t2;
	Texture t3;
	Texture t4;
	RectangleShape background;
	std::list<Entity *> ent;
	std::list<Entity *>::iterator it;
	Entity * entities;
	Player *pl;
};