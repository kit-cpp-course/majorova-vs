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
	 * �����������, ����������� ������ ent ����������, ������� ����� ���������� � ���� ����� ���
	 * @param ent ������, ���������� � ���� ��� ��������
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
	 * ������������ ������������ ������ � ����������
	 * @param pl �����
	 * @param ent ������ ���� ���������, ������� �������� � ���� ����� ���
	 * @param it �������� ��� ������ �� ������
	 */

	void Collision(Player &pl, std::list<Entity*> &ent, std::list<Entity*>::iterator &it) {
		
		for (it = ent.begin(); it != ent.end(); it++)
		{
			if ((pl.body.getPosition().x + 50 > (*it)->body.getPosition().x) && (pl.body.getPosition().x + 20 < (*it)->body.getPosition().x + 68)
				&& (pl.body.getPosition().y + 70 > (*it)->body.getPosition().y) && (pl.body.getPosition().y + 70 < (*it)->body.getPosition().y + 14) && (pl.dy > 0)) {
				if ((*it)->name == "EasyEnemy" || (*it)->name == "EasyEnemy2") { //���� ������� � ������ - ��� ����, �� �� ������������
					(*it)->body.setPosition(1000, 1000);
				}
				pl.dy = -10;
			}
		}

	}

	/*
	 * �������� �� ��������� ������ � ����������� �������� �� ���� �������� ������ ������
	 * @param pl �����
	 * @param ent ������ ���� ���������, ������� �������� � ���� ����� ���
	 * @param it �������� ��� ������ �� ������
	 */

	void Move(Player &pl, std::list<Entity*> &ent, std::list<Entity*>::iterator &it) {

		for (it = ent.begin(); it != ent.end(); it++)
		{
			(*it)->Move();
		}

		if (pl.body.getPosition().y < pl.h)
		{
			for (it = ent.begin(); it != ent.end(); it++) {
				pl.body.setPosition({ pl.body.getPosition().x, pl.h }); // ���������� � ������ ����������� �� 200

				(*it)->body.setPosition({ (*it)->body.getPosition().x, (*it)->body.getPosition().y - pl.dy }); // ��� ��������� ��������� �� ��� ������� �� dy

						// ����� ��������� ����������� �� ������ ����� ������, ��� ����������������
						// �� ������� ����� ������ �� ��������� ����������� �.
				if ((*it)->body.getPosition().y > 533) {
					(*it)->body.setPosition((*it)->body.getPosition().x, 0.0f);
					(*it)->body.setPosition((std::rand() % 400), (*it)->body.getPosition().y);

				}
			}
		}
		pl.Move();

	}

	/*
	 * �������� �� ��������� ������ � ���� ��������� � ����
	 * @param pl �����
	 * @param ent ������ ���� ���������, ������� �������� � ���� ����� ���
	 * @param it �������� ��� ������ �� ������
	 * @param window ����, ��� ���������� ��������
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
	 * ������� ����. ���������� ������� ���������, ������������, �������������� ������������.
	 * @param pl �����
	 * @param ent ������ ���� ���������, ������� �������� � ���� ����� ���
	 * @param it �������� ��� ������ �� ������
	 * @param window ����, ��� ���������� ��������
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