#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int v,e;
int graph[101][101];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>v>>e;
    for(int i=1;i<=v;++i)for(int j=1;j<=v;++j)graph[i][j]=INF;
    for(int i=1;i<=v;++i)graph[i][i]=0;
    for(int i=0;i<e;++i){
        int a,b; cin>>a>>b;
        graph[a][b]=1;
    }
    for(int k=1;k<=v;++k)
        for(int i=1;i<=v;++i)
            for(int j=1;j<=v;++j)
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
    for(int i=1;i<=v;++i){
        int res=0;
        for(int j=1;j<=v;++j)if(graph[i][j]>=INF&&graph[j][i]>=INF)res++;
        cout<<res<<'\n';
    }
    return 0;
}
/*
1.비교가 가능하다-> 간선이 있다
유추하여 비교한다-> 간선을 타고 올라가 두 정점이 이어져 있으면 유추 가능
비교가 불가능하다 -> 두 정점이 단절되어 있다.
2.A와 B를 비교한다->B에서 A로 갈수 있거나, A에서 B로 갈 수 있다.
3.문제를 그래프로 표현해봐야 한다.
*/