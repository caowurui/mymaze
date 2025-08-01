#include "const.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QRandomGenerator>
#include <QPainter>

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
    QTimer *timer;
    void on_timer();

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

protected:
    void paintEvent(QPaintEvent *event)override;


};
#endif // MAINWINDOW_H
