#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <Gosu/AutoLink.hpp>
#include <Gosu/Gosu.hpp>

#include <boost/shared_ptr.hpp>

enum ZOrder {
	zBackground,
	zStars,
	zPlayer,
	zUI
};

class Block {
private:
	boost::shared_ptr<Gosu::Image> image;
	double posX, posY;
	Gosu::Color colour;

public:
	explicit Block(Gosu::Graphics& graphics, double x, double y);
	double x() const;
	double y() const;

	void draw();
};

#endif //__BLOCK_H__