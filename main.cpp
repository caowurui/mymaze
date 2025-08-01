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
struct Photo{
    int y,x;
    int nx,ny;
    Texture ph;
    Photo(){y=x=(p_w+w_w);}
    void LoadPhoto(const char*name){
        Image img;
        if(FileExists(name))
            img=LoadImage(name);
        else{
            img=GenImageColor(Photo_Width,Photo_Width,BLUE);
        }
        ph=LoadTextureFromImage(img);
        UnloadImage(img);
    }
    void UnloadPhoto(){
        UnloadTexture(ph);
    }
    void DrawPhoto(){
        DrawTexture(ph,x,y,WHITE);
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
            case KEY_UP:case KEY_W:
                up();
                break;
            case KEY_DOWN:case KEY_S:
                down();
                break;
            case KEY_LEFT:case KEY_A:
                left();
                break;
            case KEY_RIGHT:case KEY_D:
                right();
                break;
        }
    }
};
Photo role;

void DrawMaze();

int main(){
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(Win_x,Win_y,TITLE);
    SetTargetFPS(fps);

    GenerateMaze();
    role.LoadPhoto("    photo.png    ");

    while(!WindowShouldClose())
    {
        role.move(GetKeyPressed());
        BeginDrawing();
        ClearBackground(BackgroundColor);
        DrawMaze();
        role.DrawPhoto();
        EndDrawing();
    }

    role.UnloadPhoto();
    CloseWindow();
    return 0;
}

void GenerateMaze(){
}

void shuttle_dire(int a[4]){
}


void DrawMaze(){
    for(int i=0;i<m_y;i++)
        for(int j=0;j<m_x;j++){
            if(!maze[i][j].dire[0]){
                DrawRectangle(p_w*(j+1)-w_w,p_w*(i+1),p_w+2*w_w,w_w,WallColor);
            }
            if(!maze[i][j].dire[1]){
                DrawRectangle(p_w*(j+1)-w_w,p_w*(i+2)-w_w,p_w+2*w_w,w_w,WallColor);
            }
            if(!maze[i][j].dire[2]){
                DrawRectangle(p_w*(j+1),p_w*(i+1)-w_w,w_w,p_w+2*w_w,WallColor);
            }
            if(!maze[i][j].dire[3]){
                DrawRectangle(p_w*(j+2)-w_w,p_w*(i+1)-w_w,w_w,p_w+2*w_w,WallColor);
            }
        }
    DrawRectangle(p_w-w_w,p_w-w_w,p_w*m_x+2*w_w,w_w,WallColor);
    DrawRectangle(p_w-w_w,p_w-w_w,w_w,p_w*m_y+2*w_w,WallColor);
    DrawRectangle(p_w*(m_x+1),p_w-w_w,w_w,p_w*m_y+2*w_w,WallColor);
    DrawRectangle(p_w-w_w,p_w*(m_y+1),p_w*m_x+2*w_w,w_w,WallColor);
}
*/
