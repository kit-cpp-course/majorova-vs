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
	 * @param texture  Изображение игрока
	 * @param Name Имя
	 * @param X Начальная координата по оси Х
	 * @param Y Начальная координата по оси У
	 */

	Player(sf::Texture * texture, std::string Name, float X, float Y) : Entity(texture, Name, X, Y) {
		
	}

    /*
	 * Функция, описывающая движение игрока. При нажатии клавиш "Left" и "Right" на клавиатуре персонаж передвигается
	 * влево и вправо соответственно. Игрок постоянно находится в движении.
	 */

	void Move();
	
private:
	float  h = 200; // Предельная координата по оси Y
	int score = 0; // Счёт игрока
};