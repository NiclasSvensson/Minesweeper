#ifndef CONSTANTS
#define CONSTANTS

const int WIDTH = 20;
const int HEIGHT = 10;
const int BOMBS = 35;

const int MARGIN = 40;
const int BETWEEN = 5;
const int SQUARE_WIDTH = 50;
const int EXPLOSION_WIDTH = 64;
const int WINDOW_WIDTH = WIDTH*SQUARE_WIDTH + (WIDTH-1)*BETWEEN + 2*MARGIN;
const int WINDOW_HEIGHT = HEIGHT*SQUARE_WIDTH + (HEIGHT-1)*BETWEEN + MARGIN + 120;

const sf::Color COLOR_FADE(255, 255, 255, 100);
const sf::Color COLOR_NO_FADE(255, 255, 255, 255);

static_assert(BOMBS < WIDTH*HEIGHT, "More bombs than sqaures!");

#endif