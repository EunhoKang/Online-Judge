#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

struct node{
    int y,x;
    int black;
};

int n;
int grid[50][50];
int visited[50][50][2500];//대략 육백만개의 int형. 128mb 안에 수용 가능.
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};//for문 활용을 위해 데이터화

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){//미로 초기 상태 구현
        string tp;
        cin>>tp;
        for(int j=0;j<n;++j){
            grid[i][j]=tp[j]-'0';
        }
    }
    node st={0,0,0};
    queue<node> Q;
    Q.push(st);
    int res=INF;
    while(!Q.empty()){//큐가 모두 빌 때까지 반복.
        node current=Q.front();
        Q.pop();
        if(current.x==n-1 && current.y==n-1){//마지막 지점에 닿으면 최소 비교 후 continue.
            res=min(res,current.black);
            continue;
        }
        for(int i=0;i<4;++i){//방문하지 않은 방 탐색 후 큐에 추가. 검은 방의 경우 방문한 검은 방의 수 증가.
            if(0<=current.y+dy[i] && current.y+dy[i]<n
            && 0<=current.x+dx[i] && current.x+dx[i]<n){
                if(visited[current.y+dy[i]][current.x+dx[i]][current.black]!=1){
                    if(grid[current.y+dy[i]][current.x+dx[i]]==1){
                        Q.push({current.y+dy[i],current.x+dx[i],current.black});
                    }else{
                        Q.push({current.y+dy[i],current.x+dx[i],current.black+1});
                    }
                    visited[current.y+dy[i]][current.x+dx[i]][current.black]=1;
                }
            }
        }
    }
    cout<<res;
    return 0;
}

/*
방의 개수가 최대 2500개이고 몇개의 방을 없애야 하는지 모르므로 브루트는 불가능.
BFS에서 통과한 검은 방의 수를 추가하는 식으로 탐색.

이 문제는 최단거리 알고리즘으로도 풀 수 있다.
흰 방의 가중치를 0, 검은 방의 가중치를 1로 두고
최단 거리 탐색을 하면 가장 적은 수의 검은 방을 방문하게 된다. 
*/