#include "Texts.h"

void Texts::initFont(std::string font_adress)
{
	fonts = new Fonts(font_adress);
	this->setFont(*fonts);
}

void Texts::initString(std::string str)
{
	originalStr = str;
	this->setString(originalStr);
}

Texts::Texts(std::string str, std::string font_adress) : sf::Text(*fonts)
{
	initFont(font_adress);
	initString(str);
}

Texts::~Texts()
{
	delete fonts;
}

void Texts::streamText(std::string str, float var)
{
	std::stringstream sStream;
	sStream << str << var;

	this->setString(sStream.str());
}
