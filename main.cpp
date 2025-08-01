#include<raylib.h>

#define TITLE "迷宫"
#define fps 20
#define BackgroundColor RAYWHITE
#define WallColor GRAY
#define Maze_x 20
#define Maze_y 15
#define Wall_Width 6
#define Photo_Width 20
const char Photo_Name[]="photo.png";

#define m_x Maze_x
#define m_y Maze_y
#define w_w (Wall_Width/2.0)
#define p_w (Photo_Width+Wall_Width)
#define Win_x (p_w*(Maze_x+2))
#define Win_y (p_w*(Maze_y+2))
const int step=(p_w);

struct MazeNode{
    bool dire[4];
    bool vis;
    MazeNode(){clear();}
    void clear(){vis=false;for(int i=0;i<4;i++)dire[i]=0;}
};
MazeNode maze[m_y][m_x];
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

void GenerateMaze();
void shuttle_dire(int a[4]);
void dfs(int y,int x);
void DrawMaze();

int main(){
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(Win_x,Win_y,TITLE);
    SetTargetFPS(fps);

    GenerateMaze();
    role.LoadPhoto(Photo_Name);

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
    for(int i=0;i<m_y;i++)for(int j=0;j<m_x;j++)maze[i][j].clear();
    maze[0][0].vis=true;
    dfs(0,0);
}

void shuttle_dire(int a[4]){
    int w;
    w=GetRandomValue(0,3);
    a[w]=0;
    w=GetRandomValue(0,3);
    while(a[w]!=0){w++;}
    a[w%4]=1;
    w=GetRandomValue(0,3);
    while(a[w]!=0){w++;}
    a[w%4]=2;
    w=GetRandomValue(0,3);
    while(a[w]!=0){w++;}
    a[w%4]=3;
}

void dfs(int y,int x){
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
