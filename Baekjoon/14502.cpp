#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int h,w;
int grid[8][8];
int spread[8][8];
int wall[8][8];
vector<vector<int>> virus;
int res;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int SafeArea(){
    int cnt=0;
    for(int i=0;i<h;++i)for(int j=0;j<w;++j){
        if(!grid[i][j]&&!spread[i][j]&&!wall[i][j])cnt++;
        spread[i][j]=0;
    }
    return cnt;
}

int BFS(){
    queue<vector<int>> Q;
    for(vector<int> coordinate : virus)Q.push(coordinate);
    while(!Q.empty()){
        int x=Q.front()[1];
        int y=Q.front()[0];
        Q.pop();
        if(0<=x&&x<w&&0<=y&&y<h){
            spread[y][x]=1;
            if(!grid[y+1][x]&&!spread[y+1][x]&&!wall[y+1][x])Q.push({y+1,x});
            if(!grid[y-1][x]&&!spread[y-1][x]&&!wall[y-1][x])Q.push({y-1,x});
            if(!grid[y][x+1]&&!spread[y][x+1]&&!wall[y][x+1])Q.push({y,x+1});
            if(!grid[y][x-1]&&!spread[y][x-1]&&!wall[y][x-1])Q.push({y,x-1});
        }
    }
    int res=SafeArea();
    return res;
}

void solve(int cnt, int y, int x){
    if(cnt==3){
        res=max(res,BFS());
        return;
    }else{
        for(int i=y;i<h;++i){
            for(int j=x;j<w;++j){
                if(grid[i][j]==0&&wall[i][j]==0){
                    wall[i][j]=1;
                    solve(cnt+1,i,j);
                    wall[i][j]=0;
                }
            }
            x=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>h>>w;
    for(int i=0;i<h;++i)for(int j=0;j<w;++j){
        cin>>grid[i][j];
        if(grid[i][j]==2)virus.push_back({i,j});
    }
    solve(0,0,0);
    cout<<res;
    return 0;
}

/*
1.BFS 사용, 벽이 딱 세개고 격자가 작으므로 백트레킹 활용.
---
2.조합으로 세도록 코드를 변경한다.
*/