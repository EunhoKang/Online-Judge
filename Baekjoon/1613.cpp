#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int v,e;
int graph[401][401];
int ans;
vector<int> A,B;

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
    cin>>ans;
    for(int i=0;i<ans;++i){
        int a,b; cin>>a>>b;
        A.push_back(a);B.push_back(b);
    }
    for(int i=0;i<ans;++i){
        if(graph[A[i]][B[i]]<INF)cout<<-1<<'\n';
        else if(graph[B[i]][A[i]]<INF)cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}
/*
1.순서비교 가능 여부 문제. 플로이드 알고리즘을 활용한다.
*/