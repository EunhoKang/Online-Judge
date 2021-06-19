#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,m;
int grid[300][300];
int nextgrid[300][300];
int visited[300][300];
int maxice=0;
int nextice=0;
const int dy[4]={0,0,1,-1};
const int dx[4]={1,-1,0,0};

struct node{
    int y;
    int x;
};

int DFS(int y, int x){
    if(grid[y][x]<=0)return 0;
    int res=1;
    nextgrid[y][x]=grid[y][x];
    for(int i=0;i<4;++i){
        if(0<=y+dy[i]&&y+dy[i]<n&&0<=x+dx[i]&&x+dx[i]<m){
            if(visited[y+dy[i]][x+dx[i]]==0){
                visited[y+dy[i]][x+dx[i]]=1;
                int adjust=DFS(y+dy[i],x+dx[i]);
                res+=adjust;
            }
            if(grid[y+dy[i]][x+dx[i]]==0 && nextgrid[y][x]>0)nextgrid[y][x]--;
        }
    }
    if(nextgrid[y][x]<=0)nextice--;
    return res;
}

int BFS(){
    queue<node> q;
    int year=0;
    int currentice=maxice;
    nextice=maxice;
    q.push({0,0});
    visited[0][0]=1;
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        q.pop();
        for(int i=0;i<4;++i){
            if(0<=y+dy[i]&&y+dy[i]<n&&0<=x+dx[i]&&x+dx[i]<m
            &&visited[y+dy[i]][x+dx[i]]==0){
                visited[y+dy[i]][x+dx[i]]=1;
                if(grid[y+dy[i]][x+dx[i]]>0){
                    int cnt=DFS(y+dy[i],x+dx[i]);
                    if(cnt!=currentice)return year;
                    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
                        grid[i][j]=nextgrid[i][j];
                        nextgrid[i][j]=0;
                        visited[i][j]=0;
                    }
                    currentice=nextice;
                    while(!q.empty())q.pop();
                    q.push({0,0});
                    visited[0][0]=1;
                    year++;
                    break;
                }
                q.push({y+dy[i],x+dx[i]});
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        cin>>grid[i][j];
        if(grid[i][j]>0)maxice++;
    }
    cout<<BFS();
    return 0;
}

/*
1.먼저 어떤 빙하 하나를 찾고(BFS),이 빙하가 모든 빙하와 연결되어있는지 탐색(DFS)
----
변수 초기화를 제대로 하지 않은 대가는 굉장히 크다.
코드를 제대로 쓰자. 그렇지 않으면 4배의 시간을 더 들여야 할지도 모른다.
*/