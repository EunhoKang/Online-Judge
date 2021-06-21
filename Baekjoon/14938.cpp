#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int e,m,v;
int item[101];
int graph[101][101];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>e>>m>>v;
    for(int i=1;i<=e;++i)for(int j=1;j<=e;++j)graph[i][j]=INF;
    for(int i=1;i<=e;++i)graph[i][i]=0;
    for(int i=1;i<=e;++i)cin>>item[i];
    for(int i=0;i<v;++i){
        int a,b,c; cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    for(int k=1;k<=e;++k)
        for(int i=1;i<=e;++i)
            for(int j=1;j<=e;++j)
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
    int res=0;
    for(int i=1;i<=e;++i){
        int sum=0;
        for(int j=1;j<=e;++j)if(graph[i][j]<=m)sum+=item[j];
        res=max(res,sum);
    }
    cout<<res;
    return 0;
}

/*
1.플로이드로 최단거리 전부 뒤지고 각 정점 순회하면서 브루트포스.
정점의 수가 100개인데 시간복잡도가 O(V^3)이라 압도됨. 다행이 E<100이라 사용가능.
2.방향이 없는 그래프이므로 양쪽 다 처리해줘야 한다.
*/