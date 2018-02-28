#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics.hpp>
#include "Maze.h"
#include "Player.h"
#include "Model.h"

class View
{
    public:
        View();
        virtual ~View();
        //void Draw(sf::RenderWindow*, Maze*, Player*);
        void Draw(sf::RenderWindow*, Model*);

    protected:

    private:
        int squareSize = 40;
        sf::Texture crateTexture;
        sf::Texture brickTexture;
        sf::Texture openTexture;
        sf::Texture targetTexture;
        sf::Texture crateOnTargetTexture;
        sf::Texture playerTexture;
        //sf::RenderWindow window;
};

#endif // VIEW_H
