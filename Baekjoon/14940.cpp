#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

const int dy[4]={0,0,1,-1};
const int dx[4]={1,-1,0,0};
int n,m;
int grid[1000][1000];
int visited[1000][1000];
vector<int> start;

struct node{
    int y;
    int x;
    int depth;
};

void bfs(){
    queue<node> q;
    q.push({start[0],start[1],0});
    grid[start[0]][start[1]]=0;
    visited[start[0]][start[1]]=1;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            if(0<=cur.y+dy[i]&&cur.y+dy[i]<n&&
            0<=cur.x+dx[i]&&cur.x+dx[i]<m&&
            grid[cur.y+dy[i]][cur.x+dx[i]]!=0&&
            visited[cur.y+dy[i]][cur.x+dx[i]]!=1){
                q.push({cur.y+dy[i],cur.x+dx[i],cur.depth+1});
                grid[cur.y+dy[i]][cur.x+dx[i]]=cur.depth+1;
                visited[cur.y+dy[i]][cur.x+dx[i]]=1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        cin>>grid[i][j];
        if(grid[i][j]==2)start={i,j};
    }
    bfs();
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(visited[i][j]==0 && grid[i][j]!=0)cout<<-1<<' ';
            else cout<<grid[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}

/*
1.bfs의 특성을 이용한다.
2.배열에서 방문 처리를 미리 해야 시간이 단축된다.
*/