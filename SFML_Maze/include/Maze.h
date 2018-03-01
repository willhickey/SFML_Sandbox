#ifndef MAZE_H
#define MAZE_H
#include <string>

//enum MazeBlock {Wall, Passage};
enum Directions {TheLeft, TheRight, Above, Below};

struct Square
{
    bool IsWall = 0;        //1
    bool HasCrate = 0;      //2
    bool IsTarget = 0;      //4
};

class Maze
{
    public:
        //Maze(int, int, std::string);
        Maze();
        Maze(int, int, char**);
        virtual ~Maze();
        void Initialize(int, int, char**);
        bool IsWall(int, int);
        bool IsTarget(int, int);
        bool HasCrate(int, int);
        void SetCrate(int, int, bool);
        bool PlayerCanEnterFrom(int, int, Directions);
        int Height();
        int Width();
    protected:

    private:

        int width, height;
        Square** maze;
};

#endif // MAZE_H
