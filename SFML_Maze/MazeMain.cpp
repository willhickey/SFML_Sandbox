/*
Author: Will Hickey
Date: 2018-02-28
Description:        Bare bones implementation of the classic Sokoban while learning SFML

TODO:
    Fix clunky input (probably need input thread)
    Move counter & timer
*/


#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <future>
#include "include\View.h"
#include "include\Model.h"
#include "include\KeyboardListener.h"

int main(int argc, char *argv[])
{
    char* mazeFilePath;
    if(argc >= 2){
        mazeFilePath = argv[1];
    }
    else{
        mazeFilePath = "../../data/maze01.txt";
    }
    std::ifstream mazeFile;
    mazeFile.open(mazeFilePath);

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
    int windowHeight = height * 40;
    int windowWidth = width * 40;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight, 32), " - Sokoban -", sf::Style::Default);
    myView.Draw(&window, &myModel);
    std::queue<sf::Keyboard::Key> keyEvents;
    std::set<sf::Keyboard::Key> keySet { sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right};
    //Spawn the keyboard listener thread

    std::promise<void> exitSignal;
	//Fetch std::future object associated with promise
	std::future<void> futureObj = exitSignal.get_future();
    std::thread th(&KeyboardListener::listen, std::ref(keyEvents), keySet, std::move(futureObj), 0, 100);


    while (window.isOpen())
    {
        sf::Event event;
        //Here read from the keyboard listener queue
        //TODO replace this while loop with a normal game loop.
        //TODO figure out how to still catch window exit within the game loop
        while (window.pollEvent(event))
        {
            if (!keyEvents.empty()){
                sf::Keyboard::Key k = keyEvents.front();
                keyEvents.pop();
                std::cout<<k<<std::endl;
                if(k == sf::Keyboard::Down)
                {std::cout<<"Down from queue!"<<std::endl;}
            }
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
    std::cout<<"Sending exit signal"<<std::endl;
    exitSignal.set_value();
    //Wait for thread to join
    th.join();
    std::cout<<"Thread joined"<<std::endl;
    return 0;
}
