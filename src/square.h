#include "resource.h"

#ifndef SQUARE
#define SQUARE

class Square{
    private:
        Square *neighbours[8];
        bool open;
        bool bomb;
        bool flag;
        int near_flags;
        int near_bombs;
        int top;
        int left;
        int width;
        int height;
        int state;
        sf::Sprite sprite;
        sf::FloatRect bound;
        Resource* resources;
        sf::Sprite explosion_sprite;
        sf::IntRect explosion_rect;
        sf::Clock clock;
    public:
        Square(int top, int left, int width, int height, Resource *resource);
        void Open();
        void SetBomb();
        bool IsBomb();
        bool IsOpen();
        bool IsFlag();
        void SetNearBombs(int nb);
        int GetBomb();
        Square** GetNeighbours();
        void ToggleFlag();
        void IncreaseFlag();
        void DecreaseFlag();
        void Draw(sf::RenderWindow &window, bool lost, bool won, sf::Event &event);
        void Explosion(sf::RenderWindow &window);
};

#endif