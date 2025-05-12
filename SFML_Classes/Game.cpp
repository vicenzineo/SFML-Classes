#include "Game.h"


void Game::initWindow()
{
	width = 640;
	height = 360;
	title = "SFML with classes";
	vm = sf::VideoMode({ width, height });
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);
}

void Game::pollEvents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();
			}
		}
	}
}

void Game::updating()
{
	pollEvents();
}

void Game::rendering()
{
	window->clear();

	//Draw here!!!

	window->display();
}

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete window;
}

void Game::running()
{
	while (window->isOpen())
	{
		updating();
		rendering();
	}
}
