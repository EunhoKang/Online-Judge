#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int k,h,w;
int grid[200][200];
int jump[8][2]={{1,2},{-1,2},{-1,-2},{1,-2},{2,1},{-2,1},{-2,-1},{2,-1}};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int BFS(){
    queue<vector<int>> Q;
    Q.push({0,0,k,0});
    int visited[200][200][31];
    while(!Q.empty()){
        int y=Q.front()[0];
        int x=Q.front()[1];
        int knight=Q.front()[2];
        int move=Q.front()[3];
        Q.pop();
        if(0<=y&&y<h&&0<=x&&x<w&&grid[y][x]!=1&&visited[y][x][knight]!=1){
            if(y+1==h&&x+1==w)return move;
            visited[y][x][knight]=1;
            if(knight>0)for(int i=0;i<8;++i)Q.push({y+jump[i][0],x+jump[i][1],knight-1,move+1});
            for(int i=0;i<4;++i)Q.push({y+dir[i][0],x+dir[i][1],knight,move+1});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k>>w>>h;
    for(int i=0;i<h;++i)for(int j=0;j<w;++j)cin>>grid[i][j];
    cout<<BFS();
    return 0;
}

/*
1.모든 칸을 방문할 필요가 없으므로 BFS.
2.이미 방문한 칸을 다시 방문할 이유가 없으므로 다시 방문하지 않도록 한다.
3.가중치가 없는 그래프에서 bfs를 할 경우 어떤 정점을 bfs로 찾으면 그게 가장 짧은 경로가 된다.
---
4.이미 방문한 칸을 다시 방문할 수 있다.
두 가지 이동타입이 다르기 때문에 남은 점프 수에 따라 재분류 해야한다.
5.다시 보니 가로세로가 반전되어 있다.
6.조건식을 처리할 때 좀더 확실하게 짜야 한다.
*/