#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int n,m;
int graph[100][100];
int dist[100][100];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

bool OnBoard(int x, int y){
    if(0<=x && x<n && 0<=y && y<m)return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(int i=0;i<n;++i){
        string temp;cin>>temp;
        for(int j=0;j<m;++j)graph[i][j]=temp[j]-'0';
    }
    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push({0,{0,0}});
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)dist[i][j]=INF;
    dist[0][0]=0;
    while(!pq.empty()){
        int cnt=-pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        if(dist[x][y]<cnt)continue;
        for(int i=0;i<4;++i){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(OnBoard(x+dx[i],y+dy[i])){
                int ncost=graph[nx][ny];
                if(dist[nx][ny]>cnt+ncost){
                    dist[nx][ny]=cnt+ncost;
                    pq.push({-dist[nx][ny],{nx,ny}});
                }
            }
        }
    }
    cout<<dist[n-1][m-1];
    return 0;
}