#include "ball.h"

Ball::Ball(Gosu::Graphics& graphics, double vx, double vy) {
	std::wstring filename = Gosu::sharedResourcePrefix() + L"media/Smoke.png";
	image.reset(new Gosu::Image(graphics,filename));

	posX = posY = velX = velY = angle = 0;
	velX = vx; velY = vy;
}

double Ball::x() const { return posX; }
double Ball::y() const { return posY; }

void Ball::warp (double x, double y) {
	posX = x;
	posY = y;
}

void Ball::move() {
	posX += velX;
	if (posX > 600 || posX < 0) {
		velX *= -1;
	}
	posY += velY;
	if (posY > 440 || posY < 0) {
		velY *= -1;
	}
	velX *= 0.9999;
	velY *= 0.9999;
}

void Ball::draw() {
	image->draw(posX, posY,1);
}

void Ball::collide(Paddle& paddle, std::list<Block>& blocks) {
	if (posY + 50 > 480) {
		warp(320,240);
		velX = 2; velY = 2;
	}
	else if (posY + 50 >= paddle.y() && posY + 50 <= paddle.y() + 20 
		&& posX + 50 >= paddle.x() && posX <= paddle.x() + 100) {
		velY *= -1.01;
	}
	std::list<Block>::iterator cur = blocks.begin();
	while (cur != blocks.end()) {
		if (Gosu::distance(posX + 25, posY + 25,cur->x() + 25, cur->y() + 8) < 50) {
			cur = blocks.erase(cur);
			paddle.addScore(10);
		}
		else
			++cur;
	}
}