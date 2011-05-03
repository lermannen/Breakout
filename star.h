#ifndef __STAR_H__
#define __STAR_H__

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <boost/shared_ptr.hpp>

typedef std::vector< boost::shared_ptr<Gosu::Image> > Animation;

class Star {
private:
	Animation* animation;
	Gosu::Color colour;
	double posX, posY;

public:
	explicit Star (Animation& anim) {
		animation = &anim;

		colour.setAlpha(255);
		double red = Gosu::random(40,255);
		colour.setRed(static_cast<Gosu::Color::Channel>(red));
		double green = Gosu::random(40,255);
		colour.setGreen(static_cast<Gosu::Color::Channel>(green));
		double blue = Gosu::random(40,255);
		colour.setBlue(static_cast<Gosu::Color::Channel>(blue));

		posX = Gosu::random(0,640);
		posY = Gosu::random(0,480);
	}

	double x() const { return posX; }
	double y() const { return posY; }

	void draw() {
		Gosu::Image& image = *animation->at(Gosu::milliseconds() / 100 % animation->size());

		image.draw(posX - image.width() / 2.0, posY - image.height() / 2.0, 2, 1, 1, colour, Gosu::amAdditive);
	}
};

#endif //__STAR_H__