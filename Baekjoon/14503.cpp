#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1187654321;

int N,M;
int grid[50][50];
int robotposX,robotposY,robotdir;
static int posX[4]={-1,0,1,0};
static int posY[4]={0,1,0,-1};

struct node{
    int x,y,dir;
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M>>robotposX>>robotposY>>robotdir;
    for(int i=0;i<N;++i)for(int j=0;j<M;++j)cin>>grid[i][j];
    queue<node> q;
    q.push({robotposX,robotposY,robotdir});
    int cnt=0;
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int dir=q.front().dir;
        q.pop();
        if(grid[x][y]==0){
            grid[x][y]=-1;
            cnt++;
        }
        if(grid[x+posX[(dir+3)%4]][y+posY[(dir+3)%4]]==0){
            q.push({x+posX[(dir+3)%4],y+posY[(dir+3)%4],(dir+3)%4});
        }else{
            int flag=0;
            for(int i=1;i<=4;++i){
                if(grid[x+posX[(dir+4-i)%4]][y+posY[(dir+4-i)%4]]==0){
                    q.push({x+posX[(dir+4-i)%4],y+posY[(dir+4-i)%4],(dir+4-i)%4});
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                if(grid[x+posX[(dir+2)%4]][y+posY[(dir+2)%4]]==1){
                    break;
                }else{
                    q.push({x+posX[(dir+2)%4],y+posY[(dir+2)%4],dir});
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}

/*
1. BFS 문제
*/