#include "square.h"
#include "resource.h"
#include "constants.h"

#ifndef BOARD
#define BOARD

class Board {
    private:
        int rows;
        int cols;
        int bombs;
        bool lost;
        bool won;
        Resource* resource;
        Square** matrix;
        sf::Sprite restart_sprite;
        sf::FloatRect restart_bound;
        sf::Sprite laser_sprite;
        sf::IntRect laser_rect;
        sf::Clock clock;
    public:
        Board(int num_row, int num_col, int num_bombs);
        ~Board();
        int GetRows();
        int GetCols();
        Square* GetSquare(int row, int col);
        void PrepareBoard();
        void PrintBoard();
        bool Restart(sf::RenderWindow &window, sf::Event &event);
        void Laser(sf::RenderWindow &window);
        bool Draw(sf::RenderWindow &window);
};

#endif