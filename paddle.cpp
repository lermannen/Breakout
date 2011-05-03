#include "paddle.h"

Paddle::Paddle(Gosu::Graphics& graphics) {
	std::wstring filename = Gosu::sharedResourcePrefix() + L"media/Paddle.png";
	image.reset(new Gosu::Image(graphics,filename));

	posX = posY = velX = velY = angle = 0;
	score = 0;
}

double Paddle::x() const { return posX; }
double Paddle::y() const { return posY; }

unsigned Paddle::getScore() {
	return score;
}

void Paddle::addScore(unsigned int i) {
	score += i;
}

void Paddle::warp (double x, double y) {
	posX = x;
	posY = y;
}

void Paddle::goLeft() {
	angle = -90;
	accelerate();
}

void Paddle::goRight() {
	angle = 90;
	accelerate();
}

void Paddle::accelerate() {
	velX += Gosu::offsetX(angle, 0.5);
}

void Paddle::move() {
	posX += velX;
	while (posX < 0)
		posX = 0;
	while (posX > 540)
		posX = 540;

	velX *= 0.95;
}

void Paddle::draw() {
	image->draw(posX, posY,1);
}