#include "Model.h"

Model::Model(int mazeWidth, int mazeHeight, char** mazeDefinition, int startX, int startY)
{
    //instantiate
    //currentMaze = Maze(mazeWidth, mazeHeight, mazeDefinition);
    //currentPlayer = Player(startX, startY);
    currentMaze.Initialize(mazeWidth, mazeHeight, mazeDefinition);
    currentPlayer.Initialize(startX, startY);
}


Model::~Model()
{
    //dtor
}

Player* Model::GetPlayer()
{
    return &currentPlayer;
}
Maze* Model::GetMaze()
{
    return &currentMaze;
}

bool Model::MoveUp()
{
    //currentPlayer.y--;
    MoveTo(currentPlayer.x, currentPlayer.y-1, currentPlayer.x, currentPlayer.y-2);
    return true;
}
bool Model::MoveDown()
{
    //currentPlayer.y++;
    MoveTo(currentPlayer.x, currentPlayer.y+1, currentPlayer.x, currentPlayer.y+2);
    return true;
}

bool Model::MoveLeft()
{
    //currentPlayer.x--;
    MoveTo(currentPlayer.x-1, currentPlayer.y, currentPlayer.x-2, currentPlayer.y);
    return true;
}
bool Model::MoveRight()
{
    //currentPlayer.x++;
    MoveTo(currentPlayer.x+1, currentPlayer.y, currentPlayer.x+2, currentPlayer.y);
    return true;
}
bool Model::MoveTo(int toX, int toY, int toNextX, int toNextY)
{
    if(currentMaze.IsWall(toX, toY))
    {
        return false;
    }
    else if(currentMaze.HasCrate(toX, toY))
    {
        bool crateMoved = PushCrateFromTo(toX, toY, toNextX, toNextY);
        if(crateMoved)
        {
            currentPlayer.x = toX;
            currentPlayer.y = toY;
        }
        return crateMoved;
    }

    //If we get here there was neither a wall nor a crate. Just move.
    currentPlayer.x = toX;
    currentPlayer.y = toY;
    return true;
}
bool Model::PushCrateFromTo(int fromX, int fromY, int toX, int toY)
{
    if(currentMaze.IsWall(toX, toY) || currentMaze.HasCrate(toX, toY))
    {
        return false;
    }
    else
    {
        currentMaze.SetCrate(fromX, fromY, false);
        currentMaze.SetCrate(toX, toY, true);
        return true;
    }
}
bool Model::CheckIfWinConditionMet()
{
    for(int i=0; i<currentMaze.Height(); i++)
    {
        for(int j=0; j<currentMaze.Width(); j++)
        {
            if(currentMaze.IsTarget(j, i) && !currentMaze.HasCrate(j, i))
                return false;
        }
    }
    return true;
}
