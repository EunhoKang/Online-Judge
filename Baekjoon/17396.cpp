#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int n,m;
int ward[100000];
vector<pair<int,int>> vertex[100000];
long long dist[100000];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>ward[i];
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        vertex[a].push_back({b,c});
        vertex[b].push_back({a,c});
    }
    for(int i=0;i<n;++i)dist[i]=20000000000;
    priority_queue<pair<int,long long>> pq;
    dist[0]=0;
    pq.push({dist[0],0});
    while(!pq.empty()){
        int cur=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(ward[cur]==1 && cur!=n-1)continue;
        if(dist[cur]<cost)continue;
        for(int i=0;i<vertex[cur].size();++i){
            int next=vertex[cur][i].first;
            int nCost=vertex[cur][i].second;
            if(dist[next]>cost+nCost){
                dist[next]=cost+nCost;
                pq.push({-dist[next],next});
            }
        }
    }
    cout<<(dist[n-1]>=INF ? -1: dist[n-1]);
    return 0;
}

/*
1. 값이 안 나오면 항상 최대 크기를 확인하자.
*/