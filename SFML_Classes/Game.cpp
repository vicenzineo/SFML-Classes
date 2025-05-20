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

void Game::initImages()
{
	images = new Images({ width, height });
}

void Game::initRandomize()
{
	randomize = new Randomize();
}

void Game::initGOL()
{
	gol = new GOL({ width, height });
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

	gol->update(); 

	//randomize->randomizeFloat(0.0f, 10.0f);
	//float randVar = randomize->RandomF();

	//texts->streamText("Random number: ", randVar);

	/*for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			std::uint8_t c = (x & y) ^ x;
			c *= 255;
			sf::Color color = sf::Color(c, c, c);

			images->setPixel({ x, y }, color);
		}
	}
	images->updateTexture();*/
}

void Game::rendering()
{
	window->clear();

	//Draw here!!!
	//window->draw(*texts);
	//window->draw(images->getSprite());
	window->draw(gol->getSprite());

	window->display();
}

Game::Game()
{
	initWindow();
	//initTexts();
	//initImages();
	//initRandomize();
	initGOL();
}

Game::~Game()
{
	delete window;
	//delete texts;
	//delete images;
	//delete randomize;
	delete gol;
}

void Game::running()
{
	while (window->isOpen())
	{
		updating();
		rendering();
	}
}
