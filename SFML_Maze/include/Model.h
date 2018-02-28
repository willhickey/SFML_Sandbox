#ifndef MODEL_H
#define MODEL_H
#include "Maze.h"
#include "Player.h"

class Model
{
    public:
        Model(int, int, char**, int, int);
        virtual ~Model();
        bool MoveLeft();
        bool MoveRight();
        bool MoveDown();
        bool MoveUp();
        bool MoveTo(int, int, int, int);
        bool PushCrateFromTo(int, int, int, int);
        bool CheckIfWinConditionMet();
        Player* GetPlayer();
        Maze* GetMaze();

    protected:

    private:
        Maze currentMaze;
        Player currentPlayer;
};

#endif // MODEL_H
