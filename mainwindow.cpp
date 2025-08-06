#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0,0,Win_x,Win_y);

    maze.GenerateMaze();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(WallColor);

    maze.DrawMaze(&p);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    maze.roleMove(event->key());
    update();
}
