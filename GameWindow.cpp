#include "GameWindow.h"

GameWindow::GameWindow() : Window(640, 480, false), font(graphics(), 
							Gosu::defaultFontName(), 20), player(graphics()), ball(graphics(), 5, 5) {

    setCaption(L"Gosu Tutorial Game");

    std::wstring filename = Gosu::sharedResourcePrefix() + L"media/Space.png";
    backgroundImage.reset(new Gosu::Image(graphics(), filename, false));

	for (int i = 0; i < 10; ++i)
		blocks.push_back(Block(graphics(), 45+55*i, 35));
	for (int i = 0; i < 10; ++i)
		blocks.push_back(Block(graphics(), 45+55*i, 60));

	ball.warp(200,100);
    player.warp(320, 430);
}

void GameWindow::update()
{
    if (input().down(Gosu::kbLeft) || input().down(Gosu::gpLeft))
        player.goLeft();
    if (input().down(Gosu::kbRight) || input().down(Gosu::gpRight))
        player.goRight();
    player.move();
	ball.move();
	ball.collide(player, blocks);
}

void GameWindow::draw() {
    player.draw();
	ball.draw();
    backgroundImage->draw(0, 0, zBackground);

    for (std::list<Block>::iterator i = blocks.begin(); i != blocks.end(); ++i) {
        i->draw();
    }

    font.draw(L"Score: " + boost::lexical_cast<std::wstring>(player.getScore()),
        10, 10, zUI, 1, 1, Gosu::Colors::yellow);
}

void GameWindow::buttonDown(Gosu::Button btn) {
    if (btn == Gosu::kbEscape)
        close();
}