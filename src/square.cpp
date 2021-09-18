#include <SFML/Graphics.hpp>
#include <iostream>
#include "square.h"
#include "resource.h"
#include "constants.h"

Square::Square(int top, int left, int width, int height, Resource *resource): top(top), left(left), width(width), height(height){
    open = false;
    bomb = false;
    flag = false;
    near_flags = 0;
    state = 0;
    resources = resource;

    sprite = sf::Sprite();
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    sprite.setPosition(left, top);
    bound = sprite.getGlobalBounds();

    explosion_sprite = sf::Sprite();
    explosion_sprite.setTexture(resources -> Explosion());
    explosion_sprite.setPosition(left-(EXPLOSION_WIDTH - SQUARE_WIDTH)/2, top-(EXPLOSION_WIDTH - SQUARE_WIDTH)/2);
    explosion_rect = sf::IntRect(0, 0, EXPLOSION_WIDTH, EXPLOSION_WIDTH);
}

void Square::Open(){
    open = true;
    if (near_bombs == 0 && !IsBomb()){
        for (int i = 0; i < 8; i++){
            if (neighbours[i] == NULL || neighbours[i] -> IsOpen() || neighbours[i] -> IsFlag()){
                continue;
            } else {
                neighbours[i] -> Open();
            }
        }
    }
}

void Square::SetBomb(){
    bomb = true;
}

bool Square::IsBomb(){
    return bomb;
}

bool Square::IsOpen(){
    return open;
}

bool Square::IsFlag(){
    return flag;
}

void Square::SetNearBombs(int nb){
    near_bombs = nb;
}

int Square::GetBomb(){
    if (bomb){
        return 9;
    } else {
        return near_bombs;
    } 
}

Square** Square::GetNeighbours(){
    return neighbours;
}

void Square::ToggleFlag(){
    flag = !flag;
    for (int i = 0; i < 8; i++){
        if (neighbours[i] != NULL && flag) {
            neighbours[i] -> IncreaseFlag();
        } else if (neighbours[i] != NULL && !flag) {
            neighbours[i] -> DecreaseFlag();
        }
    }
}

void Square::IncreaseFlag(){
    near_flags ++;
}

void Square::DecreaseFlag(){
    near_flags --;
}

void Square::Draw(sf::RenderWindow &window, bool lost, bool won, sf::Event &event){
    if (!IsOpen()){
        if (lost && IsBomb()){
            sprite.setTexture(resources -> HiddenBomb());
        } else if (won && IsBomb()){
            sprite.setTexture(resources -> Correct());
        } else if (!IsFlag()){
            sprite.setTexture(resources -> EmptySquare());
        } else {
            sprite.setTexture(resources -> Flag());
        }
    } else {
        if (bomb){
            sprite.setTexture(resources -> Bomb());
        } else if (near_bombs == 0){
            sprite.setTexture(resources -> Zero());
        } else if (near_bombs == 1){
            sprite.setTexture(resources -> One());
        } else if (near_bombs == 2){
            sprite.setTexture(resources -> Two());
        } else if (near_bombs == 3){
            sprite.setTexture(resources -> Three());
        } else if (near_bombs == 4){
            sprite.setTexture(resources -> Four());
        } else if (near_bombs == 5){
            sprite.setTexture(resources -> Five());
        } else if (near_bombs == 6){
            sprite.setTexture(resources -> Six());
        } else if (near_bombs == 7){
            sprite.setTexture(resources -> Seven());
        } else if (near_bombs == 8){
            sprite.setTexture(resources -> Eight());
        }
    }

    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    if (bound.contains(mouse_position.x, mouse_position.y) && !lost && !won){
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && !IsFlag()){
            if (!IsOpen()){
                Open();
            } else {
                for (int i = 0; i < 8; i++){
                    if (neighbours[i] != NULL && !(neighbours[i] -> IsFlag()) && near_flags == near_bombs) {
                        neighbours[i] -> Open();
                    }
                }
            }
        } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right) {
            if (!IsOpen()) {
                ToggleFlag();
            }
        }
        sprite.setScale(1.02f, 1.02f);
        sprite.setColor(COLOR_FADE);
    } else {
        sprite.setScale(1.0f, 1.0f);
        sprite.setColor(COLOR_NO_FADE);
    }
    
    window.draw(sprite);
}

void Square::Explosion(sf::RenderWindow &window){
    explosion_sprite.setTextureRect(explosion_rect);
    if (state <= 8){
        window.draw(explosion_sprite);
        if (clock.getElapsedTime().asSeconds() > 0.1f){
            explosion_rect.top += 64;
            state ++;
            clock.restart();
        }
    }
}