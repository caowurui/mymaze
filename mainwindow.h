#include "maze.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public:
    Maze maze;

protected:
    void paintEvent(QPaintEvent *event)override;

protected:
    void keyPressEvent(QKeyEvent *event)override;


};
#endif // MAINWINDOW_H
