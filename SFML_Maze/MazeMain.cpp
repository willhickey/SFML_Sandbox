
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
//#include "include\Maze.h"
#include "include\View.h"
//#include "include\Player.h"
#include "include\Model.h"
#define PI 3.1415926535

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
    //std::vector<std::vector<int>> startupMaze;

    //Maze myMaze = Maze(width, height, startupMaze);
    //Player myPlayer = Player(playerY, playerX);
    Model myModel = Model(width, height, startupMaze, playerX, playerY);

    for(int i=0; i<height; i++){
        delete[] startupMaze[i];
    }
    delete[] startupMaze;
    View myView;

    sf::RenderWindow window(sf::VideoMode(400, 400, 32), " - Sokoban -", sf::Style::Default);
    //sf::RenderWindow window(sf::VideoMode(1600, 900, 32), "SFML works!", sf::Style::Fullscreen);
    while (window.isOpen())
    {
        //Draw
        //Wait
        //Get Input

        //float deltaTime = clock.restart().asSeconds();
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
        //myView.Draw(&window, &myMaze, &myPlayer);

        }
    }

 /* sf::RenderWindow window(sf::VideoMode(1600, 900, 32), "SFML works!", sf::Style::Fullscreen);
    sf::CircleShape shape(20.f, 60);
    shape.setFillColor(sf::Color::Blue);
    float x, y;
    float xCenter = 400, yCenter = 300;
    float speed = 100;
    float angle = 0;
    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            yCenter -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            yCenter += speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            xCenter -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            xCenter += speed * deltaTime;

        x = 20*cos(angle * PI / 180.0);
        y = 20*sin(angle * PI / 180.0);

        shape.setPosition(xCenter+x, yCenter+y);
        window.clear();
        window.draw(shape);
        window.display();
        angle+=deltaTime*100;
        if(angle==360)
            angle=0;
    }
*/
    return 0;
}
