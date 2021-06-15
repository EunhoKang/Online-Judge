#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,m;
int grid[1000][1000];
int visited[1000][1000][2];
const int dy[4]={0,0,1,-1};
const int dx[4]={1,-1,0,0};

struct node{
    int y;
    int x;
    int path;
    int broke;
};

int BFS(){
    queue<node> q;
    memset(visited,0,sizeof(visited));
    q.push({0,0,1,0});
    visited[0][0][0]=1;
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int path=q.front().path;
        int broke=q.front().broke;
        q.pop();
        if(y==n-1&&x==m-1)return path;
        for(int i=0;i<4;++i){
            if(0<=y+dy[i]&&y+dy[i]<n&&0<=x+dx[i]&&x+dx[i]<m){
                if(broke==0 && grid[y+dy[i]][x+dx[i]]==1
                &&visited[y+dy[i]][x+dx[i]][1]==0){
                    q.push({y+dy[i],x+dx[i],path+1,1});
                    visited[y+dy[i]][x+dx[i]][1]=1;
                }else if(grid[y+dy[i]][x+dx[i]]==0
                &&visited[y+dy[i]][x+dx[i]][broke]==0){
                    q.push({y+dy[i],x+dx[i],path+1,broke});
                    visited[y+dy[i]][x+dx[i]][broke]=1;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        string s; cin>>s;
        for(int j=0;j<m;++j)grid[i][j]=s[j]-'0';
    }
    cout<<BFS();
    return 0;
}

/*
1.BFS. 벽을 부쉈는지까지 고려해 캐싱을 해야 한다.
*/