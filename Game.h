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
	 * �����������, ����������� ������ ent ����������, ������� ����� ���������� � ���� ����� ���.
	 */
	
	Game();

	/*
	 * ����������
	 */

	~Game();

	/*
	 * ������������ ������������ ������ � ����������
	 */

	void Collision();

	/*
	 * �������� �� ��������� ������ � ����������� �������� �� ���� �������� ������ ������
	 */

	void Move();

	/*
	 * �������� �� ��������� ������ � ���� ��������� � ����
	 * @param window ����, ��� ���������� ��������
	 */

	void BackgroundDraw(sf::RenderWindow & window);

	/*
	 * ������� ����. ���������� ������� ���������, ������������, �������������� ������������.
	 * @param window ����, ��� ���������� ��������
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