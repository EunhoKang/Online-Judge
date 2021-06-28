#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int e,m;
int graph[401][401];
int nxt[401][401];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>e>>m;
    for(int i=1;i<=e;++i)for(int j=1;j<=e;++j)graph[i][j]=INF;
    for(int i=1;i<=e;++i)for(int j=1;j<=e;++j)nxt[i][j]=j;
    for(int i=0;i<m;++i){
        int a,b,c; cin>>a>>b>>c;
        graph[a][b]=c;
    }
    for(int k=1;k<=e;++k)for(int i=1;i<=e;++i)for(int j=1;j<=e;++j){
        if(graph[i][j]>graph[i][k]+graph[k][j]){
            graph[i][j]=graph[i][k]+graph[k][j];
            nxt[i][j]=nxt[i][k];
        }
    }
    int res=INF;
    for(int i=1;i<=e;++i){
        res=min(res,graph[i][i]);
    }
    if(res>=INF)cout<<-1;
    else cout<<res;
    return 0;
}

/*
1.사이클을 이룰 경우 자기 자신으로 오는 최단 거리는 사이클의 길이가 된다.
*/