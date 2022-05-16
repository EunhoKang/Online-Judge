#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=87654321;

static int mX[4]={-1,0,1,0};
static int mY[4]={0,-1,0,1};
static int stromX[4][9]={{0,-1,0,1,-2,-1,0,1,0},{-2,-1,-1,-1,0,1,1,1,2},{0,1,0,-1,2,1,0,-1,0},{2,1,1,1,0,-1,-1,-1,-2}};
static int stromY[4][9]={{2,1,1,1,0,-1,-1,-1,-2},{0,-1,0,1,-2,-1,0,1,0},{-2,-1,-1,-1,0,1,1,1,2},{0,1,0,-1,2,1,0,-1,0}};
static float stromP[9]={0.02,0.1,0.07,0.01,0.05,0.1,0.07,0.01,0.02};
int grid[499][499];
int visited[499][499];
int n;
int trashed=0;

struct node{
    int x,y,dir;
};

int OnBoard(int x, int y){
    if(0<=x && x<n && 0<=y && y<n)return 1;
    else return 0;
}

void SandBrust(int x, int y, int dir, int sand){
    int amount=sand;
    for(int i=0;i<9;++i){
        int temp=sand*stromP[i];
        amount-=temp;
        if(OnBoard(x+stromX[dir][i],y+stromY[dir][i])){
            grid[x+stromX[dir][i]][y+stromY[dir][i]]+=temp;
        }else{
            trashed+=temp;
        }
    }
    if(OnBoard(x+mX[dir],y+mY[dir])){
        grid[x+mX[dir]][y+mY[dir]]+=amount;
    }else{
        trashed+=amount;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>grid[i][j];
    queue<node> q;
    q.push({n/2,n/2,0});
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int dir=q.front().dir;
        q.pop();
        visited[x][y]=1;
        if(OnBoard(x+mX[(dir+1)%4],y+mY[(dir+1)%4])){
            if(visited[x+mX[(dir+1)%4]][y+mY[(dir+1)%4]]==0){
                q.push({x+mX[(dir+1)%4],y+mY[(dir+1)%4],(dir+1)%4});
                SandBrust(x+mX[(dir+1)%4],y+mY[(dir+1)%4],(dir+1)%4,grid[x+mX[(dir+1)%4]][y+mY[(dir+1)%4]]);
            }else{
                if(OnBoard(x+mX[dir],y+mY[dir])){
                    q.push({x+mX[dir],y+mY[dir],dir});
                    SandBrust(x+mX[dir],y+mY[dir],dir,grid[x+mX[dir]][y+mY[dir]]);
                }else{
                    break;
                }
            }
        }else{
            break;
        }
    }
    cout<<trashed;
}

/*
1. 토네이도를 어떻게 돌리느냐가 관건. 토네이도는 진행 방향 왼쪽에 방문했던 칸이 없다면 왼쪽으로 회전하고, 있다면 앞으로 전진한다.
만약 앞으로도 갈 수 없다면 토네이도 소멸.
2. 토네이도에 따른 값들은 모두 캐싱해야 한다. 
*/