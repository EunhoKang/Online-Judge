#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

struct node{//입력 방식에 따라 할 경우 z,y,x순으로 두는 게 가장 자연스럽다.
    int z;
    int y;
    int x;
    int t;
};

int m,n,h;
int tomato[100][100][100];
int visited[100][100][100];
//6방향 모듈화.
static int dz[6]={0,0,0,0,1,-1};
static int dx[6]={0,0,1,-1,0,0};
static int dy[6]={1,-1,0,0,0,0};

bool AllSet(){//모든 토마토가 익었는지 확인.
    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<m;++k)if(tomato[i][j][k]==0)return false;
        }
    }
    return true;
}
bool isInside(int _z,int _y, int _x){//좌표가 상자 안에 포함되는지 확인.
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
    queue<node> q;//BFS를 위해 큐 생성
    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<m;++k)if(tomato[i][j][k]==1)q.push({i,j,k,0});//익은 것들을 큐에 넣는다.
        }
    }
    node current;
    while(!q.empty()){
        current=q.front();
        q.pop();
        tomato[current.z][current.y][current.x]=1;//먼저 방문한 토마토는 익는다.
        if(AllSet()){//만약 모든 토마토가 있었으면, 현재 노드의 시간 출력후 종료.
            cout<<current.t;
            return 0;
        }
        for(int i=0;i<6;++i){//6개의 탐색 방향에 대해
            if(isInside(current.z+dz[i],current.y+dy[i],current.x+dx[i])){//좌표가 박스 안에 포함되고
                if(visited[current.z+dz[i]][current.y+dy[i]][current.x+dx[i]]==0){//아직 방문하지 않은 노드이며
                    if(tomato[current.z+dz[i]][current.y+dy[i]][current.x+dx[i]]==0){//익지 않은 토마토일 경우
                        visited[current.z+dz[i]][current.y+dy[i]][current.x+dx[i]]=1;//해당 노드를 방문한다.
                        q.push({current.z+dz[i],current.y+dy[i],current.x+dx[i],current.t+1});
                    }
                }
            }
        }
    }
    if(!AllSet())cout<<-1;//만약 BFS 종료 후에도 안 익은 토마토가 있으면, -1 출력
    else cout<<current.t;
    return 0;
}

/*
1.x,y,z,여기에 시간까지 포함된 노드 탐색
2.좌표 방향을 잘 잡아줘야 한다.
3.중복 처리 시 이런 문제는 한번 익은 토마토는 다시 방문할 필요가 없으므로, 
토마토의 익음 유무가 t축에 대한 방문 여부 처리를 대신해준다. 즉, t에 대해서는 방문 처리를 고려하지 않아도 된다.
*/
