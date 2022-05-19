#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n,m,st,ed;
vector<pair<int,int>> vertex[100001];
int dist[100001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>st>>ed;
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        vertex[a].push_back({b,c});
        vertex[b].push_back({a,c});
    }
    priority_queue<pair<int,int>> pq;
    pq.push({INF,st});
    while(!pq.empty()){
        int cur=pq.top().second;
        int cost=pq.top().first;
        pq.pop();
        for(int i=0;i<vertex[cur].size();++i){
            int next=vertex[cur][i].first;
            int nCost=vertex[cur][i].second;
            if(dist[next]<min(nCost,cost)){
                dist[next]=min(nCost,cost);
                pq.push({dist[next],next});
            }
        }
    }
    cout<<dist[ed];
    return 0;
}

/*
1. 다익스트라 변형 문제.
최단거리 연산 부분만 최소값 간선 구하는 연사으로 바꾼다.
*/
