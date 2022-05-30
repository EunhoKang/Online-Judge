#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=21000000;

int T;
int m,n,k;
int x[2501], y[2501];
int grid[51][51];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int onBoard(int x, int y){
    if(0<=x && x<n && 0<=y && y<m)return 1;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        memset(grid,0,sizeof(grid));
        cin>>m>>n>>k;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<k;++i){
            cin>>y[i]>>x[i];
            grid[x[i]][y[i]]=1;
        }
        q.push({{x[0],y[0]},1});
        grid[x[0]][y[0]]=0;
        int res=0;
        while(res<k){
            auto node=q.front();
            q.pop();
            res++;
            if(res==k){
                cout<<node.second<<'\n';
                break;
            }
            for(int i=0;i<4;++i){
                if(onBoard(node.first.first+dx[i],node.first.second+dy[i]==1)){
                    if(grid[node.first.first+dx[i]][node.first.second+dy[i]]==1){
                        grid[node.first.first+dx[i]][node.first.second+dy[i]]=0;
                        q.push({{node.first.first+dx[i],node.first.second+dy[i]},node.second});
                    }
                }
            }
            if(q.empty())for(int i=0;i<n;++i){
                int flag=0;
                for(int j=0;j<m;++j)if(grid[i][j]==1){
                    q.push({{i,j},node.second+1});
                    grid[i][j]=0;
                    flag=1;
                    break;
                }
                if(flag==1)break;
            }
        }
    }
    return 0;
}