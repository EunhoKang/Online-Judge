#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

struct point{
    int x;
    int y;
};

int r,c;
string inputgrid[250];
int grid[250][250];
int visited[250][250];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

point findTarget(){
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(visited[i][j]==0 && grid[i][j]!=1)return {i,j};
        }
    }
    return {0,0};
}
bool isFinish(){
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(grid[i][j]!=1 && visited[i][j]==0)return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>r>>c;
    for(int i=0;i<r;++i){
        cin>>inputgrid[i];
        for(int j=0;j<c;++j){
            if(inputgrid[i][j]=='#')grid[i][j]=1;
            else if(inputgrid[i][j]=='o')grid[i][j]=2;
            else if(inputgrid[i][j]=='v')grid[i][j]=3;
            else grid[i][j]=0;
        }
    }
    int sheep=0;
    int wolves=0;
    while(!isFinish()){
        queue<point> q;
        point init=findTarget();
        q.push(init);
        visited[init.x][init.y]=1;
        int currentsheep=0;
        int currentwolves=0;
        while(!q.empty()){
            point target=q.front();
            q.pop();
            if(grid[target.x][target.y]==2)currentsheep++;
            else if(grid[target.x][target.y]==3)currentwolves++;
            for(int i=0;i<4;++i){
                if(0<=target.x+dx[i] && target.x+dx[i]<r && 0<=target.y+dy[i] && target.y+dy[i]<c){
                    if(grid[target.x+dx[i]][target.y+dy[i]]!=1 && visited[target.x+dx[i]][target.y+dy[i]]==0){
                        q.push({target.x+dx[i],target.y+dy[i]});
                        visited[target.x+dx[i]][target.y+dy[i]]=1;
                    }
                }
            }
        }
        if(currentsheep>currentwolves){
            sheep+=currentsheep;
        }else{
            wolves+=currentwolves;
        }
    }
    cout<<sheep<<" "<<wolves;
    return 0;
}
/*
1. 해당 구역 전부 BFS -> 불가능할 경우 가장 행과열이 작은 미방문 정점에서 다시 시작
2. 모든 구역 방문 시 종료, 정점을 다시 찾을 때마다 양과 늑대 수 계산 
*/