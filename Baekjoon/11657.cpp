#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int e,v;
vector<pair<int,int>> graph[501];
long long shortest[501];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>e>>v;
    for(int i=0;i<v;++i){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    for(int i=2;i<=e;++i)shortest[i]=INF;
    shortest[1]=0;
    int mCycle=0;
    for(int i=1;i<=v;++i){
        for(int j=1;j<=e;++j){
            for(int k=0;k<graph[j].size();++k){
                if(shortest[j]!=INF&&
                    shortest[graph[j][k].first]>graph[j][k].second+shortest[j]){
                    shortest[graph[j][k].first]=graph[j][k].second+shortest[j];
                    if(i==v)mCycle=1;
                }
            }
        }
    }
    if(mCycle)cout<<-1;
    else{
        for(int i=2;i<=e;++i){
            if(shortest[i]>=INF)cout<<-1<<'\n';
            else cout<<shortest[i]<<'\n';
        }
    }
    return 0;
}

/*
1.음수 간선이 있으므로 벨만포드 사용.
---
사이클을 도는 경우 값이 매우 커지거나 작아질 수 있다.
안전하게 long long을 사용.

또한 정점의 최단거리가 무한대일 경우 검사가 필요없으므로 이를 넘김으로써
INF-1과 같은 판별하기 어려운 값을 배제한다.
*/