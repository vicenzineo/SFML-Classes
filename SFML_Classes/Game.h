#pragma once
#include <string.h>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Times.h"
#include "Texts.h"

class Game
{
private:
	
	unsigned int width;
	unsigned int height;
	std::string title;
	sf::VideoMode vm;
	sf::RenderWindow* window;

	Times times;
	Texts* texts;

	void initWindow();
	void initTexts();

	void pollEvents();

	void updating();
	void rendering();

public:

	Game();
	~Game();

	void running();
};