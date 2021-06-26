#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int e,m;
int item[101];
int graph[201][201];
int nxt[201][201];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>e>>m;
    for(int i=1;i<=e;++i)for(int j=1;j<=e;++j)graph[i][j]=INF;
    for(int i=1;i<=e;++i)for(int j=1;j<=e;++j)nxt[i][j]=j;
    for(int i=1;i<=e;++i)graph[i][i]=0;
    for(int i=0;i<m;++i){
        int a,b,c;cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    for(int k=1;k<=e;++k)for(int i=1;i<=e;++i)for(int j=1;j<=e;++j){
        if(graph[i][j]>graph[i][k]+graph[k][j]){
            graph[i][j]=graph[i][k]+graph[k][j];
            nxt[i][j]=nxt[i][k];
        }
    }
    for(int i=1;i<=e;++i){
        for(int j=1;j<=e;++j){
            if(i==j)cout<<"- ";
            else cout<<nxt[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}

/*
1.플로이드 경로탐색 문제. 조건을 만족할 때마다 다음 정점을 기록한다.
2.i->j로 가는 최단 경로에서 k를 반드시 거칠 경우 가장 먼저 방문하는 정점은,
i->k로 가는 최단 경로에서 가장 먼저 방문하는 정점이다.
*/