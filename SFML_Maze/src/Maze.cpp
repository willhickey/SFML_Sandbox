#include "Maze.h"
Maze::Maze()
{
}
Maze::Maze(int w, int h, char** mazeDefinition)
{
    Initialize(w, h, mazeDefinition);
    /*width = w;
    height = h;
    maze = new Square*[height];
    for(int i=0; i<height; i++)
    {
        maze[i] = new Square[width];
        for(int j=0; j<width; j++)
        {
            //maze[i][j]=new Square();
            if(mazeDefinition[i][j]=='1')
                maze[i][j].IsWall = 1;
            else if(mazeDefinition[i][j]=='8')
                maze[i][j].HasCrate = 1;
            else if(mazeDefinition[i][j]=='9')
                maze[i][j].IsTarget = 1;
        }
    }*/
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
            //switch this to use bits instead. Currently can't put a crate on a target.
            //maze[i][j]=new Square();
            if(mazeDefinition[i][j]=='1')
                maze[i][j].IsWall = 1;
            else if(mazeDefinition[i][j]=='8')
                maze[i][j].HasCrate = 1;
            else if(mazeDefinition[i][j]=='9')
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
    //dtor
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
void Maze::SetCrate(int x, int y, bool newValue)
{
    maze[y][x].HasCrate = newValue;
}
