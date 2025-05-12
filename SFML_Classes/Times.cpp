#include "Times.h"

Times::Times()
{
	nextDeltaTime();
}

Times::~Times()
{
}

void Times::nextDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

float Times::getDeltaTime() const
{
	return deltaTime;
}
