#pragma once
#include "Entity.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//Класс, описывающий платформу

class Platforms : public Entity {
public:

	/*
	 * Консруктор.
	 * @param texture  Изображение платформы
	 * @param Name Имя
	 * @param X Начальная координата по оси X
	 * @param Y Начальная координата по оси Y
	 * @param W Длина платформы
	 * @param H Высота платформы
	 */

	Platforms(sf::Texture * texture, std::string Name, float X, float Y, float W, float H) : Entity(texture, Name, X, Y, W, H) {
		
	}

	/*
	 * Функция, описывающая движение платформы. Платформы неподвижны.
	 */

	void Move()
	{

	}
};
