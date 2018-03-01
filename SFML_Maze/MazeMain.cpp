/*
Author: Will Hickey
Date: 2018-02-28
Description:        Bare bones implementation of the classic Sokoban while learning SFML

TODO:
    Pass maze file as command line parameter
    Dynamic window size based on maze size
    Fix clunky input
    Move counter & timer
*/


#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "include\View.h"
#include "include\Model.h"

int main()
{
    std::ifstream mazeFile;
    mazeFile.open("../../data/maze01.txt");
    std::string heightStr, widthStr, playerYStr, playerXStr;
    std::getline(mazeFile, heightStr);
    std::getline(mazeFile, widthStr);
    std::getline(mazeFile, playerYStr);
    std::getline(mazeFile, playerXStr);
    int height = stoi(heightStr);
    int width = stoi(widthStr);
    int playerY = stoi(playerYStr);
    int playerX = stoi(playerXStr);

    char **startupMaze;
    startupMaze = new char *[height];
    for(int i=0; i<height; i++){
        startupMaze[i] = new char[width];
        for(int j=0; j<width; j++){
            //mazeFile >> myChar;
            mazeFile >> startupMaze[i][j];
        }
    }
    Model myModel = Model(width, height, startupMaze, playerX, playerY);

    for(int i=0; i<height; i++){
        delete[] startupMaze[i];
    }
    delete[] startupMaze;
    View myView;

    sf::RenderWindow window(sf::VideoMode(400, 400, 32), " - Sokoban -", sf::Style::Default);
    //sf::RenderWindow window(sf::VideoMode(1600, 900, 32), "", sf::Style::Fullscreen);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            myView.Draw(&window, &myModel);
            if(myModel.CheckIfWinConditionMet())
            {
                window.close();
                std::cout<<"You Win!"<<std::endl;
            }

            sf::sleep(sf::milliseconds(100));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                myModel.MoveUp();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                myModel.MoveDown();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                myModel.MoveLeft();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                myModel.MoveRight();

        }
    }
    return 0;
}
