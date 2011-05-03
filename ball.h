#ifndef __BALL_H__
#define __BALL_H__

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <boost/scoped_ptr.hpp>

#include <list>

#include "block.h"
#include "paddle.h"

class Ball {
private:
	boost::scoped_ptr<Gosu::Image> image;
	double posX, posY, velX, velY, angle;

public:
	explicit Ball(Gosu::Graphics& graphics, double vx, double vy);

	double x() const;
	double y() const;

	void warp (double x, double y);

	void move();

	void draw();

	void collide(Paddle& paddle, std::list<Block>& blocks);
};
#endif //__BALL_H__