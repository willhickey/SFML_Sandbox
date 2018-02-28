#include "View.h"
#include "Model.h"

View::View()
{
    //
    crateTexture.loadFromFile("../../image/crate.png");
    brickTexture.loadFromFile("../../image/brick.png");
    openTexture.loadFromFile("../../image/open.png");
    targetTexture.loadFromFile("../../image/target.png");
    crateOnTargetTexture.loadFromFile("../../image/crateOnTarget.png");
    playerTexture.loadFromFile("../../image/playerTransparent.png");
}

View::~View()
{
    //dtor
}

//void View::Draw(sf::RenderWindow *window, Maze *currentMaze, Player *currentPlayer)
void View::Draw(sf::RenderWindow *window, Model *currentModel)
{
    Maze* currentMaze = currentModel->GetMaze();
    Player* currentPlayer = currentModel->GetPlayer();
    window->clear();
    sf::Sprite tile;
    for(int i=0; i<currentMaze->Height(); i++)
    {
        for(int j=0; j<currentMaze->Width(); j++)
        {
            /*
            sf::RectangleShape shp(sf::Vector2f(squareSize,squareSize));
            if(currentMaze->IsBlocked(j, i))
                shp.setFillColor(sf::Color::Blue);
            else
                shp.setFillColor(sf::Color::White);
            shp.setPosition(j*squareSize, i*squareSize);
            window->draw(shp);
            */


            if(currentMaze->IsWall(j, i))
                tile.setTexture(brickTexture);
            else if(currentMaze->IsTarget(j, i) && currentMaze->HasCrate(j, i))
                tile.setTexture(crateOnTargetTexture);
            else if(currentMaze->IsTarget(j, i))
                tile.setTexture(targetTexture);
            else if(currentMaze->HasCrate(j, i))
                tile.setTexture(crateTexture);
            else
                tile.setTexture(openTexture);
            tile.setTextureRect(sf::IntRect(0, 0, 40, 40));
            tile.setPosition(j*squareSize, i*squareSize);
            window->draw(tile);

        }
    }
    tile.setTexture(playerTexture);
    tile.setPosition(currentPlayer->GetX()*squareSize, currentPlayer->GetY()*squareSize);
    window->draw(tile);
    window->display();
}
