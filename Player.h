#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Game;
//Класс, описывающий игрока

class Player : public Entity {
public:
	friend Game;

	/*
	 * Конструктор. 
	 * @param texture  Текстура игрока
	 * @param Name Имя
	 * @param X Начальная координата по оси X
	 * @param Y Начальная координата по оси Y
	 */

	Player(sf::Texture * texture, std::string Name, float X, float Y ) : Entity(texture,  Name, X, Y){
		
	}

        /*
	 * Функция, описывающая движение игрока. При нажатии клавиш "Left" и "Right" на клавиатуре персонаж передвигается влево и вправо
	 * соответственно. Игрок постоянного находится в движении (меняется координата Y).
	 */

	void Move() {
		const float moveSpeed = 3;
		dy += 0.2;
		body.move({ 0, dy });
		if (body.getPosition().y > 480) {
			dy = -10;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			body.move({ -moveSpeed, 0 });
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			body.move({ moveSpeed, 0 });

		if (body.getPosition().x < -100) body.setPosition({ 390, body.getPosition().y });
		if (body.getPosition().x > 390) body.setPosition({ -100, body.getPosition().y });
	}
	
private:
	float  h = 200; // Предельная координата по оси Y
	int Score; // Счёт игрока
};
