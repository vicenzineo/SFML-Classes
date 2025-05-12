#pragma once
#include <sstream>
#include "Fonts.h"

class Texts : public sf::Text
{

private:

	std::string originalStr;
	Fonts *fonts;

	void initFont(std::string font_adress);
	void initString(std::string str);

public:

	Texts(std::string str, std::string font_adress);
	~Texts();

	void streamText(std::string str = "", float var = 0.0f);
};