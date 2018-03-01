#include "Maze.h"
Maze::Maze()
{
}
Maze::Maze(int w, int h, char** mazeDefinition)
{
    Initialize(w, h, mazeDefinition);
}
void Maze::Initialize(int w, int h, char** mazeDefinition)
{
    width = w;
    height = h;
    maze = new Square*[height];
    for(int i=0; i<height; i++)
    {
        maze[i] = new Square[width];
        for(int j=0; j<width; j++)
        {
            //0=open, 1=wall, 2=crate, 4=target, 6=crate on target
            //3, 5 & 7 aren't really valid
            if(((mazeDefinition[i][j]-'0') & 1) == 1)
                maze[i][j].IsWall = 1;
            if(((mazeDefinition[i][j]-'0') & 2) == 2)
                maze[i][j].HasCrate = 1;
            if(((mazeDefinition[i][j]-'0') & 4) == 4)
                maze[i][j].IsTarget = 1;
        }
    }
}
int Maze::Height()
{
    return height;
}
int Maze::Width()
{
    return width;
}

Maze::~Maze()
{
    for(int i=0; i<height; i++)
    {
        delete[] maze[i];
    }
    delete[] maze;
}

bool Maze::IsWall(int x, int y)
{
    return maze[y][x].IsWall;
}
bool Maze::HasCrate(int x, int y)
{
    return maze[y][x].HasCrate;
}

bool Maze::IsTarget(int x, int y)
{
    return maze[y][x].IsTarget;
}
//Moving crates isn't transactional at this level, but the Model handles that.
void Maze::SetCrate(int x, int y, bool newValue)
{
    maze[y][x].HasCrate = newValue;
}
