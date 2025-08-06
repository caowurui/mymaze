#include "maze.h"


Maze::Maze()
{
    role=new Photo(this);
    maze=QVector<QVector<MazeNode>>(m_y,QVector<MazeNode>(m_x));
    rand=new QRandomGenerator();
}

Maze::~Maze()
{
    delete rand;
    delete role;
}

void Maze::GenerateMaze()
{

    for(int i=0;i<m_y;i++)for(int j=0;j<m_x;j++)maze[i][j].clear();
    maze[0][0].vis=true;
    dfs(0,0);
}

void Maze::shuttle_dire(int a[4])
{

    int w;
    w=rand->bounded(4);
    a[w]=0;
    w=rand->bounded(4);
    while(a[w]!=0){w++;}
    a[w%4]=1;
    w=rand->bounded(4);
    while(a[w]!=0){w++;}
    a[w%4]=2;
    w=rand->bounded(4);
    while(a[w]!=0){w++;}
    a[w%4]=3;
}


void Maze::dfs(int y,int x){
    int a[4]={0};
    shuttle_dire(a);
    maze[y][x].vis=true;
    for(int i=0;i<4;i++){
        switch(a[i]){
            case 0:
                if(y>=1&&!maze[y-1][x].vis){
                    maze[y][x].dire[0]=true;
                    maze[y-1][x].dire[1]=true;
                    dfs(y-1,x);
                }
                break;
            case 1:
                if(y<=m_y-2&&!maze[y+1][x].vis){
                    maze[y][x].dire[1]=true;
                    maze[y+1][x].dire[0]=true;
                    dfs(y+1,x);
                }
                break;
            case 2:
                if(x>=1&&!maze[y][x-1].vis){
                    maze[y][x].dire[2]=true;
                    maze[y][x-1].dire[3]=true;
                    dfs(y,x-1);
                }
                break;
            case 3:
                if(x<=m_x-2&&!maze[y][x+1].vis){
                    maze[y][x].dire[3]=true;
                    maze[y][x+1].dire[2]=true;
                    dfs(y,x+1);
                }
                break;
        }
    }
}

void Maze::DrawMaze(QPainter *p)
{
    for(int i=0;i<m_y;i++)
        for(int j=0;j<m_x;j++){
            if(!maze[i][j].dire[0]){
                p->fillRect(p_w*(j+1)-w_w,p_w*(i+1),p_w+2*w_w,w_w,WallColor);
            }
            if(!maze[i][j].dire[1]){
                p->fillRect(p_w*(j+1)-w_w,p_w*(i+2)-w_w,p_w+2*w_w,w_w,WallColor);
            }
            if(!maze[i][j].dire[2]){
                p->fillRect(p_w*(j+1),p_w*(i+1)-w_w,w_w,p_w+2*w_w,WallColor);
            }
            if(!maze[i][j].dire[3]){
                p->fillRect(p_w*(j+2)-w_w,p_w*(i+1)-w_w,w_w,p_w+2*w_w,WallColor);
            }
        }

    p->fillRect(p_w-w_w,p_w-w_w,p_w*m_x+2*w_w,w_w,WallColor);
    p->fillRect(p_w-w_w,p_w-w_w,w_w,p_w*m_y+2*w_w,WallColor);
    p->fillRect(p_w*(m_x+1),p_w-w_w,w_w,p_w*m_y+2*w_w,WallColor);
    p->fillRect(p_w-w_w,p_w*(m_y+1),p_w*m_x+2*w_w,w_w,WallColor);

    role->DrawPhoto(p);
}

void Maze::roleMove(int key)
{
    role->move(key);
}



Photo::Photo(Maze*maze){
    y=x=(p_w+w_w);
    ph=QPixmap(":/role/photo.png");
    m=maze;
}
void Photo::DrawPhoto(QPainter*p){
    p->drawPixmap(x,y,ph);
}

void Photo::move(int ley){
    int nx=x/p_w-1;
    int ny=y/p_w-1;

    switch(ley){
        case Qt::Key_Up:case Qt::Key_W:
            if(m->maze[ny][nx].dire[0])y-=step;
            break;
        case Qt::Key_Down:case Qt::Key_S:
            if(m->maze[ny][nx].dire[1])y+=step;
            break;
        case Qt::Key_Left:case Qt::Key_A:
            if(m->maze[ny][nx].dire[2])x-=step;
            break;
        case Qt::Key_Right:case Qt::Key_D:
            if(m->maze[ny][nx].dire[3])x+=step;
            break;
    }
}
