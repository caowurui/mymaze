#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0,Win_x,Win_y);

    timer = new QTimer(parent);
    //connect(timer,SIGNAL(timeout()),this,SLOT(on_timer()));
    //timer->start(1000.0/fps);

    rand=new QRandomGenerator();
    GenerateMaze();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete rand;
}

void MainWindow::on_timer()
{

}

void MainWindow::GenerateMaze()
{

    for(int i=0;i<m_y;i++)for(int j=0;j<m_x;j++)maze[i][j].clear();
    maze[0][0].vis=true;
    dfs(0,0);
}

void MainWindow::shuttle_dire(int a[4])
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


void MainWindow::dfs(int y,int x){
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

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(WallColor);

    for(int i=0;i<m_y;i++)
        for(int j=0;j<m_x;j++){
            if(!maze[i][j].dire[0]){
                p.fillRect(p_w*(j+1)-w_w,p_w*(i+1),p_w+2*w_w,w_w,QBrush(WallColor));
            }
            if(!maze[i][j].dire[1]){
                p.fillRect(p_w*(j+1)-w_w,p_w*(i+2)-w_w,p_w+2*w_w,w_w,WallColor);
            }
            if(!maze[i][j].dire[2]){
                p.fillRect(p_w*(j+1),p_w*(i+1)-w_w,w_w,p_w+2*w_w,WallColor);
            }
            if(!maze[i][j].dire[3]){
                p.fillRect(p_w*(j+2)-w_w,p_w*(i+1)-w_w,w_w,p_w+2*w_w,WallColor);
            }
        }
    p.fillRect(p_w-w_w,p_w-w_w,p_w*m_x+2*w_w,w_w,WallColor);
    p.fillRect(p_w-w_w,p_w-w_w,w_w,p_w*m_y+2*w_w,WallColor);
    p.fillRect(p_w*(m_x+1),p_w-w_w,w_w,p_w*m_y+2*w_w,WallColor);
    p.fillRect(p_w-w_w,p_w*(m_y+1),p_w*m_x+2*w_w,w_w,WallColor);
}



