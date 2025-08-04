#include <mainwindow.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
/*


int main(){

    role.LoadPhoto("    photo.png    ");

    while()
    {
        BeginDrawing();
        ClearBackground(BackgroundColor);
        DrawMaze();
        role.DrawPhoto();
        EndDrawing();
    }

    role.UnloadPhoto();
}


*/
