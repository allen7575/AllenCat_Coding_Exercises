#include <queue>
#include <utility>
#include <iostream>
#include <fstream>

using namespace std;

#define INF 10000000
#define MAX_N 10
#define MAX_M 10

typedef pair<int, int> P;

int maze[MAX_N][MAX_M];
int d[MAX_N][MAX_M];
int dx=1, dy=1;
int Sx,Sy,Gx,Gy;

void init(){
    char ch;
    fstream mazefile("maze.txt", fstream::in);
    
    for(int i=0;i<MAX_N*MAX_M;i++){
        do{
            mazefile >> noskipws >> ch;
        }while(ch=='\n');
        
        cout << ch;
        if(i%MAX_M == MAX_M-1) cout <<'\n';
        maze[i/MAX_N][i%MAX_M] = ch;
        d[i/MAX_N][i%MAX_M] = INF;
        
        if(maze[i/MAX_N][i%MAX_M] == 'S') {
            Sx = i/MAX_N;
            Sy = i%MAX_M;
        }
        
        if(maze[i/MAX_N][i%MAX_M] == 'G') {
            Gx = i/MAX_N;
            Gy = i%MAX_M;
        }
        
    }
}



int BFS(){
    queue<P> que;
    
    que.push(P(Sx, Sy));
    d[Sx][Sy] = 0;
    
    while(!que.empty()){
        P posi=que.front();
        que.pop();
        if(posi.first <0 || posi.second <0) continue;
        if(posi.first >= MAX_N || posi.second >= MAX_M) continue;
        //cout << "("<< posi.first<<","<<posi.second<<")"<<endl;
        switch (maze[posi.first][posi.second]){
            case 'S':
            case '.':
                maze[posi.first][posi.second] = '#';
                que.push(P(posi.first+dx,posi.second));
                que.push(P(posi.first-dx,posi.second));
                que.push(P(posi.first,posi.second+dy));
                que.push(P(posi.first,posi.second-dy));
                
                d[posi.first+dx][posi.second] = min(d[posi.first+dx][posi.second],d[posi.first][posi.second]+1);
                d[posi.first-dx][posi.second] = min(d[posi.first-dx][posi.second],d[posi.first][posi.second]+1);
                d[posi.first][posi.second+dy] = min(d[posi.first][posi.second+dy],d[posi.first][posi.second]+1);
                d[posi.first][posi.second-dy] = min(d[posi.first][posi.second-dy],d[posi.first][posi.second]+1);
                break;
            case 'G':
                //return d[posi.first][posi.second];
            case '#':
            default:
                break;
        }
    }
    
    return d[Gx][Gy];
    
}

int DFS(int Px, int Py){
    int result=INF;
    
    if(maze[Px][Py] == '#') return INF-1;
    if(maze[Px][Py] == 'G') return 0;
    if(Px <0 || Py<0 || Px >= MAX_N || Py >= MAX_M) return INF-1;

    maze[Px][Py] = '#';
    
    result = min(result,DFS(Px+1,Py)+1);
    result = min(result,DFS(Px-1,Py)+1);
    result = min(result,DFS(Px,Py+1)+1);
    result = min(result,DFS(Px,Py-1)+1);
    
    //cout << "("<< Px<<","<<Py<<")"<<endl;
    return result;
}


int main(){
    init();
    cout<<BFS();
    cout<<endl;
    init();
    //DFS(Sx,Sy);
    cout<<DFS(Sx,Sy);
    return 0;
}
