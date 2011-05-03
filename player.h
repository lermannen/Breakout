#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <boost/scoped_ptr.hpp>

#include <list>

#include "star.h"
#include "block.h"

class Player {
private:
	boost::scoped_ptr<Gosu::Image> image;
	boost::scoped_ptr<Gosu::Sample> beep;
	double posX, posY, velX, velY, angle;
	unsigned score;

public:
	explicit Player(Gosu::Graphics& graphics, Gosu::Audio& audio) {
		std::wstring filename = Gosu::sharedResourcePrefix() + L"media/Starfighter.bmp";
		image.reset(new Gosu::Image(graphics,filename));

		filename = Gosu::sharedResourcePrefix() + L"media/Beep.wav";
		beep.reset(new Gosu::Sample(audio, filename));

		posX = posY = velX = velY = angle = 0;
		score = 0;
	}

	unsigned getScore() {
		return score;
	}

	void warp (double x, double y) {
		posX = x;
		posY = y;
	}

	void turnLeft() {
		angle -= 4.5;
	}

	void turnRight() {
		angle += 4.5;
	}

	void accelerate() {
		velX += Gosu::offsetX(angle, 0.5);
		velY += Gosu::offsetY(angle, 0.5);
	}

	void move() {
		posX += velX;
		while (posX < 0)
			posX += 640;
		while (posX > 640)
			posX -= 640;

		posY += velY;
		while (posY < 0)
			posY += 480;
		while (posY > 480)
			posY -= 480;

		velX *= 0.95;
		velY *= 0.95;
	}

	void draw() {
		image->drawRot(posX, posY,1,angle);
	}

	void collectStars (std::list<Star>& stars) {
		std::list<Star>::iterator cur = stars.begin();
		while (cur != stars.end()) {
			if (Gosu::distance(posX,posY,cur->x(), cur->y()) < 35) {
				cur = stars.erase(cur);
				score += 10;
				beep->play();
			}
			else
				++cur;
		}
	}

	void collide(std::list<Block>& blocks) {
		std::list<Block>::iterator cur = blocks.begin();
		while (cur != blocks.end()) {
			if (Gosu::distance(posX,posY,cur->x(), cur->y()) < 35) {
				cur = blocks.erase(cur);
				score += 10;
				beep->play();
			}
			else
				++cur;
		}
	}
};

#endif //__PLAYER_H__