#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int grid[8][8];
int visited[8][8][8];
const int dy[9]={0,1,1,0,-1,-1,-1,0,1};
const int dx[9]={0,0,1,1,1,0,-1,-1,-1};

void MoveWalls(){
    for(int i=7;i>0;--i){
        for(int j=0;j<8;++j){
            grid[i][j]=grid[i-1][j];
        }
    }
    for(int j=0;j<8;++j)grid[0][j]=0;
}

struct node{
    int y;
    int x;
    int phase;
};

int BFS(){
    int prevP=0;
    queue<node> q;
    q.push({7,0,0});
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int p=q.front().phase;
        q.pop();
        if(prevP<p){
            MoveWalls();
        }
        prevP=p;
        if((y==0 && x==7) || p>7)return 1;
        for(int i=0;i<9;++i){
            if(0<=y+dy[i]&&y+dy[i]<8&&0<=x+dx[i]&&x+dx[i]<8&&
                grid[y+dy[i]][x+dx[i]]==0 && 
                visited[y+dy[i]][x+dx[i]][p+1]==0&& 
                (y+dy[i]==0 || grid[y+dy[i]-1][x+dx[i]]==0)){
                q.push({y+dy[i],x+dx[i],p+1});
                visited[y+dy[i]][x+dx[i]][p+1]=1;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<8;++i){
        string c;cin>>c;
        for(int j=0;j<8;++j){
            if(c[j]=='#')grid[i][j]=1;
            else grid[i][j]=0;
        }
    }
    cout<<BFS();
    return 0;
}

/*
1.만약 모든 벽이 내려가면 무조건 도달 가능하다.
벽의 위치가 계속 바뀌므로 위치뿐 아니라 시간 정보도 캐싱을 해야 한다.
2.BFS의 성질을 이용하면 벽을 움직이는 함수의 호출 횟수를 크게 줄일 수 있다.
*/