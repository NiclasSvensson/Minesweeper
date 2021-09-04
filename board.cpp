#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "resource.h"

Board::Board(int num_row, int num_col, int num_bombs){
    rows = num_row;
    cols = num_col;
    bombs = num_bombs;
    lost = false;
    won = false;
    resource = new Resource();
    matrix = new Square*[num_col*num_row];
    for (int y = 0; y < num_row; y++) {
        for (int x = 0; x < num_col; x++) {
            matrix[y*num_col + x] = new Square(MARGIN + y*(SQUARE_WIDTH+BETWEEN), MARGIN + x*(SQUARE_WIDTH+BETWEEN), SQUARE_WIDTH, SQUARE_WIDTH, resource);
        }
    }
    PrepareBoard();

    restart_sprite = sf::Sprite();
    restart_sprite.setTexture(resource -> Restart());
    restart_sprite.setScale(3.0f, 3.0f);
    restart_sprite.setPosition(MARGIN, MARGIN + HEIGHT*(SQUARE_WIDTH+BETWEEN) + BETWEEN);
    restart_bound = restart_sprite.getGlobalBounds();

    laser_sprite = sf::Sprite();
    laser_sprite.setTexture(resource -> Laser());
    laser_sprite.setScale(4.0f, float(WINDOW_HEIGHT/laser_sprite.getTextureRect().height) + 1.0f);
    laser_sprite.setPosition(-laser_sprite.getTextureRect().width, 0);
    laser_rect = sf::IntRect(0,0,10,100);
}

Board::~Board(){
    delete resource;
    for (int y = 0; y < GetRows(); y++) {
        for (int x = 0; x < GetCols(); x++) {
            delete GetSquare(y, x);
        }
    }
    delete [] matrix;
}

int Board::GetRows(){
    return rows;
}

int Board::GetCols(){
    return cols;
}

Square* Board::GetSquare(int row, int col){
    return matrix[row*GetCols() + col];
}

void Board::PrepareBoard(){
    // Place bombs randomly
    int lst[GetCols()*GetRows()] = {0};
    for (int i = 0; i < bombs; i++){
        lst[i] = 1;
    }
    srand(time(0));
    std::random_shuffle(&lst[0], &lst[GetCols()*GetRows()]);
    for (int i = 0; i < GetRows()*GetCols(); i++){
        if (lst[i] == 1){
            matrix[i]->SetBomb();
        }
    }
    // Connect Squares
    Square* square;
    Square** neighbours;
    for (int y = 0; y < GetRows(); y++){
        for (int x = 0; x < GetCols(); x++){
        square = GetSquare(y, x);
        neighbours = square -> GetNeighbours();
        int near_bombs = 0;
        int cnt = 0;
        for (int i = -1; i < 2; i++){
            for (int j = -1; j < 2; j++){
                if (i == 0 && j == 0){
                    continue;
                } else if (y+i < 0 || y+i > GetRows()-1 || x+j< 0 || x+j > GetCols()-1){
                    neighbours[cnt] = NULL;
                } else {
                    neighbours[cnt] = GetSquare(y+i, x+j);
                    if (GetSquare(y+i, x+j) -> IsBomb()){
                        near_bombs ++;
                    }
                }
                cnt ++;
            }
        }
        square -> SetNearBombs(near_bombs);
        }
    }
}

void Board::PrintBoard(){
    for (int y = 0; y < GetRows(); y++){
        for (int x = 0; x < GetCols(); x++){
            std::cout << GetSquare(y, x) -> GetBomb();
        }
        std::cout << "\n";
    }
}

bool Board::Restart(sf::RenderWindow &window, sf::Event &event){
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    if (restart_bound.contains(mouse_position.x, mouse_position.y)){
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
            return true;
        }
        restart_sprite.setColor(COLOR_FADE);
    } else {
        restart_sprite.setColor(COLOR_NO_FADE);
    }
    window.draw(restart_sprite);
    return false;
}

void Board::Laser(sf::RenderWindow &window){
    if (clock.getElapsedTime().asSeconds() > 0.05f){
        laser_rect.left += 10;
        laser_sprite.move(3.0f, 0.0f);
        if (laser_rect.left > 40){
            laser_rect.left = 0;
        }
        clock.restart();
    }
    laser_sprite.setTextureRect(laser_rect);
    if (laser_sprite.getPosition().x > window.getSize().x) {} 
    else {
        window.draw(laser_sprite);
    }
}

bool Board::Draw(sf::RenderWindow &window){
    sf::Texture texture;
    int open;
    while (window.isOpen()){
        window.clear(sf::Color(100, 100, 100));
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        open = 0;
        for (int y = 0; y < GetRows(); y++){
            for (int x = 0; x < GetCols(); x++){
                GetSquare(y, x) -> Draw(window, lost, won, event);
                if (GetSquare(y, x) -> IsOpen() && GetSquare(y, x) -> IsBomb()) {
                    lost = true;
                }
                if (GetSquare(y, x) -> IsOpen()){
                    open ++;
                }
                if (open == GetCols()*GetRows() - bombs && !lost){
                    won = true;
                }
                if (lost && GetSquare(y, x) -> IsBomb()) {
                    GetSquare(y, x) -> Explosion(window);
                }
            } 
        }
        if (Restart(window, event)) {
            return true;
        }
        if (won){
            Laser(window);
        }     
        window.display();
    }
    return false;
}
