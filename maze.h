#ifndef MAZE_H
#define MAZE_H

#include "const.h"

#include <QRandomGenerator>
#include <QPainter>

struct MazeNode{
    bool dire[4];
    bool vis;
    MazeNode(){clear();}
    void clear(){vis=false;for(int i=0;i<4;i++)dire[i]=0;}
};

class Maze;

class Photo{
    friend Maze;

    int y,x;
    QPixmap ph;
    Maze*m;

    void DrawPhoto(QPainter*p);
    void move(int ley);
public:
    Photo(Maze*);
};


class Maze{
    friend Photo;

    QVector<QVector<MazeNode>>maze;
    QRandomGenerator*rand;

    void shuttle_dire(int a[4]);
    void dfs(int y,int x);
public:
    Photo*role;
    Maze();
    ~Maze();
    void GenerateMaze();
    void DrawMaze(QPainter*p);
    void roleMove(int key);
};

#endif // MAZE_H
