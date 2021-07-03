#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int v,e,x;
vector<pair<int,int>> graph[1001];
int shortest[1001];
int go[1001];
int back[1001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>v>>e>>x;
    for(int i=0;i<e;++i){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    for(int i=1;i<=v;++i){
        priority_queue<pair<int,int>> pq;
        for(int i=1;i<=v;++i)shortest[i]=INF;
        shortest[i]=0;
        pq.push(make_pair(0,i));
        while(!pq.empty()){
            int w=-pq.top().first;
            int nxt=pq.top().second;
            pq.pop();
            if(shortest[nxt]!=w)continue;
            for(int j=0;j<graph[nxt].size();++j){
                int target=graph[nxt][j].first;
                int weight=graph[nxt][j].second;
                if(shortest[target]>w+weight){
                    shortest[target]=w+weight;
                    pq.push(make_pair(-shortest[target],target));
                }
            }
        }
        if(i==x){
            for(int j=1;j<=v;++j)back[j]=shortest[j];
        }
        else{
            go[i]=shortest[x];
        }
    }
    int res=0;
    for(int i=1;i<=v;++i){
        if(go[i]>=INF || back[i]>=INF)continue;
        res=max(res,go[i]+back[i]);
    }
    cout<<res;
    return 0;
}
/*
1.정점이 1000개나 되므로 플로이드는 사용 불가능.
2.모든 정점에 대해 다익스트라를 진행한다.
*/