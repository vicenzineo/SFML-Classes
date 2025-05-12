#pragma once
#include <string.h>
#include <SFML/Graphics.hpp>

class Game
{
private:
	
	unsigned int width;
	unsigned int height;
	std::string title;
	sf::VideoMode vm;
	sf::RenderWindow* window;

	void initWindow();

	void pollEvents();

	void updating();
	void rendering();

public:

	Game();
	~Game();

	void running();
};