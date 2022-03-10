#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

struct node{
    int z;
    int y;
    int x;
    int t;
};

int m,n,h;
int tomato[100][100][100];
int visited[100][100][100];
static int dz[6]={0,0,0,0,1,-1};
static int dx[6]={0,0,1,-1,0,0};
static int dy[6]={1,-1,0,0,0,0};

bool AllSet(){
    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<m;++k)if(tomato[i][j][k]==0)return false;
        }
    }
    return true;
}
bool isInside(int _z,int _y, int _x){
    if(0<=_x && _x<m)if(0<=_y && _y<n)if(0<=_z && _z<h)return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n>>h;
    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<m;++k)cin>>tomato[i][j][k];
        }
    }
    int day=0;
    queue<node> q;
    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<m;++k)if(tomato[i][j][k]==1)q.push({i,j,k,day});
        }
    }
    node current;
    while(!q.empty()){
        current=q.front();
        q.pop();
        tomato[current.z][current.y][current.x]=1;
        if(AllSet()){
            cout<<current.t;
            return 0;
        }
        for(int i=0;i<6;++i){
            if(isInside(current.z+dz[i],current.y+dy[i],current.x+dx[i])){
                if(visited[current.z+dz[i]][current.y+dy[i]][current.x+dx[i]]==0){
                    if(tomato[current.z+dz[i]][current.y+dy[i]][current.x+dx[i]]==0){
                        visited[current.z+dz[i]][current.y+dy[i]][current.x+dx[i]]=1;
                        q.push({current.z+dz[i],current.y+dy[i],current.x+dx[i],current.t+1});
                    }
                }
            }
        }
    }
    if(!AllSet())cout<<-1;
    else cout<<current.t;
    return 0;
}

/*
1.x,y,z,여기에 시간까지 포함된 노드 탐색
2.좌표 방향을 잘 잡아줘야 한다.
*/
