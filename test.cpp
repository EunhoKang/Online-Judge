#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

int N;
int W[300];

int V;
vector<pair<int, int>> adj[10005];

int prim(vector<pair<int, int>>& selected)
{
    selected.clear();
    vector<bool> added(V, false);
    vector<int> minWeight(V, INF);
    vector<int> parent(V, -1);
    int ret = 0;
    minWeight[0] = parent[0] = 0;
    for (int iter = 0; iter < V; ++iter)
    {
        int u = -1;
        for (int v = 0; v < V; ++v)
            if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;
        if (parent[u] != u)
            selected.push_back(make_pair(parent[u], u));
        ret += minWeight[u];
        added[u] = true;
        for (int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i].first, weight = adj[u][i].second;
            if (!added[v] && minWeight[v] > weight)
            {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> W[i];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> graph[i][j];
    return 0;
}

/*
1.무향 밀집 그래프이다.
2.N번 논에 우물을 판다 -> N번 노드에 가중치 Wi인 간선으로 연결된 우물 노드를 연결한다
우물과 연결된 간선은 반드시 하나는 있어야 하므로, 하나는 일단 무조건 간선에 추가한다.
이후 나머지 간선들로 정점을 최소한의 비용으로 연결한다. -> 최소 스패닝 트리
*/