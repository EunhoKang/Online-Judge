#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int T;
int v,e,w;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        vector< pair<int, int> > graph[501];
        long long shortest[501];
        cin>>v>>e>>w;
        for(int i=2;i<=v;++i)shortest[i]=INF;
        shortest[1]=0;
        int nCycle=0;
        for (int i=0; i<e; i++)
        {
            int a,b,c;cin>>a>>b>>c;
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }
        for (int i=0; i<w; i++)
        {
            int a,b,c;cin>>a>>b>>c;
            graph[a].push_back({b,-c});
        }
        for(int i=1;i<=v;++i){
            for(int j=1;j<=v;++j){
                for(int k=0;k<graph[j].size();++k){
                    int nxt=graph[j][k].first;
                    int weight=graph[j][k].second;
                    if(shortest[nxt]>shortest[j]+weight){
                        shortest[nxt]=shortest[j]+weight;
                        if(i==v)nCycle=1;
                    }
                }
            }
        }
        nCycle ? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';
    }
    return 0;
}
/*
1.음수 사이클이 있는지를 구분한다. 음수 사이클이 존재하는지만 판별.
---
https://4z7l.github.io/2021/03/04/algorithms-boj-1865.html
INF 비교를 빼는 이유:
1번 정점을 기준으로 시작하는데, 1번 정점과 이어지지 않은 사이클이 존재하면
이를 발견할 수가 없다.
*/