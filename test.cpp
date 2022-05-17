#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=87654321;

int n, m;
vector<pair<int,int>> graph[1001];
int st,ed;
int dist[1001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n;++i)dist[i]=INF;
    for(int i=0;i<m;++i){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    cin>>st>>ed;

    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    dist[st]=0;
    while(!pq.empty()){
        int target=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        //if(dist[target]<cost)continue;
        for(int i=0;i<graph[target].size();++i){
            int next=graph[target][i].first;
            int nCost=graph[target][i].second;
            if(dist[next]>cost+nCost){
                dist[next]=cost+nCost;
                pq.push({-dist[next],next});
            }
        }
    }
    cout<<dist[ed];
    return 0;
}

/*
1. 두 정점의 최단거리 => 다익스트라
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