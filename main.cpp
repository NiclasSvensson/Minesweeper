#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "constants.h"

int main(){

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Minesweeper", sf::Style::Titlebar | sf::Style::Close);
  
  sf::Image icon;
  icon.loadFromFile("/home/niclas/Programming/C++/minesweeper/assests/bomb.png");
  sf::Vector2u v = icon.getSize();
  window.setIcon(v.x, v.y, icon.getPixelsPtr());

  while(true){
    Board board(HEIGHT, WIDTH, BOMBS);
    //board.PrintBoard();
    if (!board.Draw(window)){
      break;
    }
  }

  return 0;
}
