#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int e,m;
int graph[101][101];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>e>>m;
    for(int i=1;i<=e;++i)for(int j=1;j<=e;++j)graph[i][j]=INF;
    for(int i=1;i<=e;++i)graph[i][i]=0;
    for(int i=0;i<m;++i){
        int a,b,c;cin>>a>>b>>c;
        graph[a][b]=min(graph[a][b],c);
    }
    for(int k=1;k<=e;++k)for(int i=1;i<=e;++i)for(int j=1;j<=e;++j){
        if(graph[i][j]>graph[i][k]+graph[k][j]){
            graph[i][j]=graph[i][k]+graph[k][j];
        }
    }
    for(int i=1;i<=e;++i){
        for(int j=1;j<=e;++j){
            if(graph[i][j]>=INF)cout<<0<<" ";
            else cout<<graph[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}

/*
1.입력할 때도 최소값만 입력받아야 한다. 같은 노선이 존재하기 때문.
---
2.무한의 경우를 따로 처리하지 않아 틀렸다.
*/