#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,m,h,w;
int grid[1000][1000];
int st[2],ed[2];
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int visited[1000][1000];

int bfs(){
    queue<vector<int>> q;
    q.push({st[0],st[1],0});
    while(!q.empty()){
        int y=q.front()[0];
        int x=q.front()[1];
        int cnt=q.front()[2];
        q.pop();
        if(y==ed[0]&&x==ed[1])return cnt;
        //
        if(x+w<m && visited[y][x+1]!=1){
            int flag=1;
            for(int i=0;i<h;++i){
                if(grid[y+i][x+w]==1){
                    flag=0;break;
                }
            }
            if(flag){
                q.push({y,x+1,cnt+1});
                visited[y][x+1]=1;
            }
        }
        //
        if(0<x&&visited[y][x-1]!=1){
            int flag=1;
            for(int i=0;i<h;++i){
                if(grid[y+i][x-1]==1){
                    flag=0;break;
                }
            }
            if(flag){
                q.push({y,x-1,cnt+1});
                visited[y][x-1]=1;
            }
        }
        //
        if(y+h<n&&visited[y+1][x]!=1){
            int flag=1;
            for(int i=0;i<w;++i){
                if(grid[y+h][x+i]==1){
                    flag=0;break;
                }
            }
            if(flag){
                q.push({y+1,x,cnt+1});
                visited[y+1][x]=1;
            }
        }
        //
        if(0<y&&visited[y-1][x]!=1){
            int flag=1;
            for(int i=0;i<w;++i){
                if(grid[y-1][x+i]==1){
                    flag=0;break;
                }
            }
            if(flag){
                q.push({y-1,x,cnt+1});
                visited[y-1][x]=1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>grid[i][j];
    cin>>h>>w>>st[0]>>st[1]>>ed[0]>>ed[1];
    st[0]--;st[1]--;ed[0]--;ed[1]--;
    cout<<bfs();
    return 0;
}

/*
1.시작점에 벽이 겹쳐 있는 경우는 없으니 제외하고,
왼쪽 최상단 점을 기준으로 잡고 그때그때 벽과 부딪히는지 확인한다.
*/