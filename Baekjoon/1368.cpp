#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

struct NaiveDisjointSet { 
    vector<int> parent; 
    NaiveDisjointSet(int n): parent(n) { 
        for (int i=0; i < n; i++) parent[i]=i; 
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

int N;
int graph[301][301];

int kruskal()
{
	int ret = 0;
    vector<pair<int, pair<int, int>>> edges;
    for (int u = 0; u <= N; ++u)
        for (int v = u + 1; v <= N; ++v)
        {
            int cost = graph[u][v];
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    sort(edges.begin(), edges.end());
    NaiveDisjointSet sets(N + 1);
    for(int i = 0; i < edges.size(); ++i)
    {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if (sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        ret += cost;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> graph[0][i];
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            cin >> graph[i][j];
    cout << kruskal();
    return 0;
}

/*
1.무향 밀집 그래프이다.
2.N번 논에 우물을 판다 -> N번 노드에 가중치 Wi인 간선으로 연결된 우물 노드를 연결한다.
우물 노드를 0번 노드로, 우물을 파는 비용을 간선의 가중치로 둔다.
3.우물과 연결된 간선은 반드시 하나는 있어야 하고, 
각 간선들로 0번을 포함한 모든 정점을 최소한의 비용으로 연결한다. -> 최소 스패닝 트리
*/