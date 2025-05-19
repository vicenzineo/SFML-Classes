#pragma once

#include <SFML/Graphics.hpp>

class Images : public sf::Image
{
private:
	sf::Sprite* sprite;
	sf::Texture* texture;

	void initTexture();
	void initSprite();
	
public: 
	Images(sf::Vector2u image_size);
	~Images();

	void updateTexture();
	sf::Sprite getSprite();
};
