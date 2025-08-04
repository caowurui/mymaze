#ifndef CONST_H
#define CONST_H


#define TITLE "迷宫"
#define fps 20
#define BackgroundColor RAYWHITE
#define WallColor Qt::gray
#define Maze_x 20
#define Maze_y 15
#define Wall_Width 6
#define Photo_Width 20


#define m_x Maze_x
#define m_y Maze_y
#define w_w (Wall_Width/2.0)
#define p_w (Photo_Width+Wall_Width)
#define Win_x (p_w*(Maze_x+2))
#define Win_y (p_w*(Maze_y+2))

const int step=(p_w);




#endif // CONST_H
