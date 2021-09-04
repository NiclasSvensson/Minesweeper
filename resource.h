#ifndef RESOURCE
#define RESOURCE

class Resource{
    private:
        std::string path;
        sf::Texture texture_empty;
        sf::Texture texture_flag;
        sf::Texture texture_correct;
        sf::Texture texture_zero;
        sf::Texture texture_one;
        sf::Texture texture_two;
        sf::Texture texture_three;
        sf::Texture texture_four;
        sf::Texture texture_five;
        sf::Texture texture_six;
        sf::Texture texture_seven;
        sf::Texture texture_eight;
        sf::Texture texture_bomb;
        sf::Texture texture_hidden_bomb;
        sf::Texture texture_explosion;
        sf::Texture texture_laser;
        sf::Texture texture_restart;
    public:
        Resource();
        sf::Texture& EmptySquare();
        sf::Texture& Bomb();
        sf::Texture& HiddenBomb();
        sf::Texture& Explosion();
        sf::Texture& Laser();
        sf::Texture& Flag();
        sf::Texture& Correct();
        sf::Texture& Restart();
        sf::Texture& Zero();
        sf::Texture& One();
        sf::Texture& Two();
        sf::Texture& Three();
        sf::Texture& Four();
        sf::Texture& Five();
        sf::Texture& Six();
        sf::Texture& Seven();
        sf::Texture& Eight();
};

#endif