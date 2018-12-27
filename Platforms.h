#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//Класс, описывающий платформу

class Platforms : public Entity {
public:

	/*
	 * Конструктор.
	 * @param texture  Изображение платформы
	 * @param Name Имя
	 * @param X Начальная координата по оси Х
	 * @param Y Начальная координата по оси У
	 * @param W Длина платформы
	 * @param H Высота платформы
	 */

	Platforms(sf::Texture * texture, std::string Name, float X, float Y, float W, float H) : Entity(texture, Name, X, Y, W, H) {
		
	}


	/*
	 * Функция, описывающая движение платформ. Платформы неподвижны.
	 */

	void Move()
	{

	}
};