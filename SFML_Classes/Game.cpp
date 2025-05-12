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

void Game::initTexts()
{
	texts = new Texts("dt: 0.000000", "Fonts/arial.ttf");
	texts->setOrigin(texts->getGlobalBounds().size / 2.0f);
	texts->setPosition({ width / 2.0f, height / 2.0f });
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

	times.getDeltaTime();

	float dt = times.getDeltaTime();
	texts->streamText("dt: ", dt);
}

void Game::rendering()
{
	window->clear();

	//Draw here!!!
	window->draw(*texts);

	window->display();
}

Game::Game()
{
	initWindow();
	initTexts();
}

Game::~Game()
{
	delete window;
	delete texts;
}

void Game::running()
{
	while (window->isOpen())
	{
		updating();
		rendering();
	}
}
