#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,m,t;
int grid[101][101];
int visited[101][101][2];
vector<int> gram={-1,-1};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int BFS(){
    queue<vector<int>> q;
    q.push({0,0,0,0});
    while(!q.empty()){
        int y=q.front()[0];
        int x=q.front()[1];
        int T=q.front()[2];
        int flag=q.front()[3];
        q.pop();
        if(T>t)return INF;
        if(y==n-1&&x==m-1)return T;
        if(grid[y][x]==2)flag=1;
        for(int i=0;i<4;++i){
            if(0<=y+dy[i]&&y+dy[i]<n&&
            0<=x+dx[i]&&x+dx[i]<m&&
            visited[y+dy[i]][x+dx[i]][flag]!=1){
                if(flag==1 || grid[y+dy[i]][x+dx[i]]!=1)
                q.push({y+dy[i],x+dx[i],T+1,flag});
                visited[y+dy[i]][x+dx[i]][flag]=1;
            }
        }
    }
    return INF;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>t;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        cin>>grid[i][j];
        if(grid[i][j]==2)gram={i,j};
    }
    int res=BFS();
    if(res>=INF)cout<<"Fail";
    else cout<<res;
    return 0;
}

/*
1.그람을 잡을 때와 잡지 않을 때를 구분하여 최소값을 구한다.
1) 그람을 잡지 않을 경우, 벽을 돌아 최소로 이동한다.
BFS를 통해 맨 끝점으로 가는 경우의 시간만 계산한다.
이때 중간 길목에 그람을 발견하더라도 잡지 않는다고 가정한다.
어차피 이를 고려하지 않아도 이 경우에 그람을 잡을 때가 최소값이 되기 때문.
2) 그람을 잡을 경우, 목적지를 그람으로 설정하고 이동한다.
이후부터는 벽을 전부 무시할 수 있으므로, 최단거리로 이동한다.
따라서 그람의 위치와 맨 끝점의 좌표 차를 더하면 된다.
2.여기서는 방문한 노드의 위치만 파악하면 된다. 
그람을 찾은 후에는 따로 계산을 하기 때문.
---
bfs는 상태를 표현할 수 있는 모든 곳에서 사용 가능하다.
최대한 알고리즘을 간단하게 짤 수 있는 방식으로 짜보자.
*/