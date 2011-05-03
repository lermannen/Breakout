#ifndef __GAMEWINDOW_H__
#define __GAMEWINDOW_H__

#include <Gosu/AutoLink.hpp>
#include <Gosu/Gosu.hpp>

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>

#include <cmath>
#include <cstdlib>
#include <list>

#include "ball.h"
#include "block.h"
#include "paddle.h"

class GameWindow : public Gosu::Window
{
    boost::scoped_ptr<Gosu::Image> backgroundImage;
    Gosu::Font font;

    Paddle player;
    std::list<Block> blocks;
	Ball ball;


public:
    GameWindow();

    void update();

    void draw();

    void buttonDown(Gosu::Button btn);
};

#endif //__GAMEWINDOW_H__