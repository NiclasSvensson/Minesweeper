#include <SFML/Graphics.hpp>
#include <filesystem>
#include "resource.h"

Resource::Resource(){
    std::string path = std::filesystem::current_path();
    texture_empty = sf::Texture();
    texture_empty.loadFromFile(path + "/assests/Empty.png");
    texture_bomb = sf::Texture();
    texture_bomb.loadFromFile(path + "/assests/bomb.png");
    texture_hidden_bomb = sf::Texture();
    texture_hidden_bomb.loadFromFile(path + "/assests/hiddenbomb.png");
    texture_explosion = sf::Texture();
    texture_explosion.loadFromFile(path + "/assests/explosion.png");
    texture_laser = sf::Texture();
    texture_laser.loadFromFile(path + "/assests/laser.png");
    texture_flag = sf::Texture();
    texture_flag.loadFromFile(path + "/assests/flag.png");
    texture_correct = sf::Texture();
    texture_correct.loadFromFile(path + "/assests/correct.png");
    texture_restart = sf::Texture();
    texture_restart.loadFromFile(path + "/assests/restart.png");
    texture_zero = sf::Texture();
    texture_zero.loadFromFile(path + "/assests/zero.png");
    texture_one = sf::Texture();
    texture_one.loadFromFile(path + "/assests/one.png");
    texture_two = sf::Texture();
    texture_two.loadFromFile(path + "/assests/two.png");
    texture_three = sf::Texture();
    texture_three.loadFromFile(path + "/assests/three.png");
    texture_four = sf::Texture();
    texture_four.loadFromFile(path + "/assests/four.png");
    texture_five = sf::Texture();
    texture_five.loadFromFile(path + "/assests/five.png");
    texture_six = sf::Texture();
    texture_six.loadFromFile(path + "/assests/six.png");
    texture_seven = sf::Texture();
    texture_seven.loadFromFile(path + "/assests/seven.png");
    texture_eight = sf::Texture();
    texture_eight.loadFromFile( path + "/assests/eight.png");
}

sf::Texture& Resource::EmptySquare(){
    return texture_empty;
}

sf::Texture& Resource::Bomb(){
    return texture_bomb;
}

sf::Texture& Resource::HiddenBomb(){
    return texture_hidden_bomb;
}

sf::Texture& Resource::Explosion(){
    return texture_explosion;
}

sf::Texture& Resource::Laser(){
    return texture_laser;
}

sf::Texture& Resource::Flag(){
    return texture_flag;
}

sf::Texture& Resource::Correct(){
    return texture_correct;
}

sf::Texture& Resource::Restart(){
    return texture_restart;
}

sf::Texture& Resource::Zero(){
    return texture_zero;
}

sf::Texture& Resource::One(){
    return texture_one;
}

sf::Texture& Resource::Two(){
    return texture_two;
}

sf::Texture& Resource::Three(){
    return texture_three;
}

sf::Texture& Resource::Four(){
    return texture_four;
}

sf::Texture& Resource::Five(){
    return texture_five;
}

sf::Texture& Resource::Six(){
    return texture_six;
}

sf::Texture& Resource::Seven(){
    return texture_seven;
}

sf::Texture& Resource::Eight(){
    return texture_eight;
}