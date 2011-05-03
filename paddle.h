#ifndef __PADDLE_H__
#define __PADDLE_H__

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <boost/scoped_ptr.hpp>

class Paddle {
private:
	boost::scoped_ptr<Gosu::Image> image;
	double posX, posY, velX, velY, angle;
	unsigned score;

public:
	explicit Paddle(Gosu::Graphics& graphics);
	double x() const;
	double y() const;

	unsigned getScore();

	void addScore(unsigned int i);

	void warp (double x, double y);

	void goLeft();

	void goRight();

	void accelerate();

	void move();

	void draw();
};

#endif __PADDLE_H__