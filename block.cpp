#include "block.h"

Block::Block(Gosu::Graphics& graphics, double x, double y) {
	std::wstring filename = Gosu::sharedResourcePrefix() + L"media/Block.png";
	image.reset(new Gosu::Image(graphics,filename));

	colour.setAlpha(255);
	double red = Gosu::random(40,255);
	colour.setRed(static_cast<Gosu::Color::Channel>(red));
	double green = Gosu::random(40,255);
	colour.setGreen(static_cast<Gosu::Color::Channel>(green));
	double blue = Gosu::random(40,255);
	colour.setBlue(static_cast<Gosu::Color::Channel>(blue));

	posX = x;
	posY = y;
}

double Block::x() const { 
	return posX; 
}
double Block::y() const { 
	return posY; 
}

void Block::draw() {
	image->draw(posX,posY,zStars,1,1,colour);
}