#include <bits/stdc++.h>
using namespace std;
const int INF = 2087654321;

int V, E;
vector<vector<int>> edges;
int parent[10001];

int find(int v)
{
    if(v == parent[v])
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
    {
        return false;
    }
    parent[u] = v;
    return true;
}

int main()
{
    cin >> V >> E;
    for(int i = 1; i <= V; ++i)
    {
        parent[i] = i;
    }
    for(int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());
    int answer = 0;
    for(int i = 0; i < E; ++i)
    {
        if(merge(edges[i][1], edges[i][2]))
        {
            answer += edges[i][0];
        }
    }
    cout << answer;
    return 0;
}