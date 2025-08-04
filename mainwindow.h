#include "const.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QRandomGenerator>
#include <QPainter>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

public:

    struct MazeNode{
        bool dire[4];
        bool vis;
        MazeNode(){clear();}
        void clear(){vis=false;for(int i=0;i<4;i++)dire[i]=0;}
    };

    MazeNode maze[m_y][m_x];

    QRandomGenerator *rand;

    void GenerateMaze();
    void shuttle_dire(int a[4]);
    void dfs(int y,int x);
    void UpdateMaze();

public:


    struct Photo{
        int y,x;
        int nx,ny;
        MazeNode maze[15][20];
        QPixmap ph;
        //Texture ph;
        Photo(){
            y=x=(p_w+w_w);
            ph=QPixmap(":/role/photo.png");
        }
        void DrawPhoto(QPainter*p){
            p->drawPixmap(x,y,ph);
        }

        void GetNode(){
            nx=x/p_w-1;
            ny=y/p_w-1;
        }
        void up(){
            if(maze[ny][nx].dire[0]==false)return;
            y-=step;
        }
        void down(){
            if(maze[ny][nx].dire[1]==false)return;
            y+=step;
        }
        void left(){
            if(maze[ny][nx].dire[2]==false)return;
            x-=step;
        }
        void right(){
            if(maze[ny][nx].dire[3]==false)return;
            x+=step;
        }
        void move(int ley){
            GetNode();
            switch(ley){
                case Qt::Key_Up:case Qt::Key_W:
                    up();
                    break;
                case Qt::Key_Down:case Qt::Key_S:
                    down();
                    break;
                case Qt::Key_Left:case Qt::Key_A:
                    left();
                    break;
                case Qt::Key_Right:case Qt::Key_D:
                    right();
                    break;
            }
        }

    };
    Photo role;

protected:
    void paintEvent(QPaintEvent *event)override;

protected:
    void keyPressEvent(QKeyEvent *event)override;


};
#endif // MAINWINDOW_H
