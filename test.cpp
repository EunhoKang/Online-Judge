#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=21000000;

int n,m;
vector<pair<int,int>> graph[801];
int must[4];
int dist[3][801];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    cin>>must[1]>>must[2];
    must[0]=1;
    must[3]=n;
    for(auto i : {0,1,2}){
        for(int j=0;j<=n;++j)dist[i][j]=INF;
        priority_queue<pair<int,int>> pq;
        dist[i][must[i]]=0;
        pq.push({dist[i][must[i]],must[i]});
        while(!pq.empty()){
            auto cur=pq.top().second;
            auto cost=-pq.top().first;
            pq.pop();
            if(dist[i][cur]<cost)continue;
            for(int j=0;j<graph[cur].size();++j){
                auto next=graph[cur][j].first;
                auto ncost=graph[cur][j].second;
                if(dist[i][next]>ncost+cost){
                    dist[i][next]=ncost+cost;
                    pq.push({-dist[i][next],next});
                }
            }
        }
    }
    int res=min(dist[0][must[1]]+dist[1][must[2]]+dist[2][must[3]],dist[0][must[2]]+dist[2][must[1]]+dist[1][must[3]]);
    if(res>=INF)cout<<-1;
    else cout<<res;
    return 0;
}

/*
1. 
*/
























/*
vector<string> split(string str,char del){
    vector<string> res;
    string s;
    stringstream ss(str);
    while(getline(ss,s,del)){
        res.push_back(s);
    }
    return res;
}
struct NaiveDisjointSet { 
    vector<int> parent; 
    NaiveDisjointSet(int n): parent(n) { 
        for (int i=0; i <= n; i++) parent[i]=i; 
    } 
    int find (int u) { 
        if (u == parent[u]) return u;  
        return parent[u]=find(parent[u]); 
    } 
    bool merge (int u, int v){
        u = find(u); v = find(v); 
        if (u == v) return false; 
        parent[u] = v; 
        return true;
    } 
};
*/