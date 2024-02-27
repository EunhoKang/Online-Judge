#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];

int find(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        return false;
    }
    parent[u] = v;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M;
    char univ[1001];
    vector<vector<int>> q;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> univ[i];
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (univ[a] != univ[b])
        {
            q.push_back({c, a, b});
        }
    }
    sort(q.begin(), q.end());
    int ans = 0;
    bool visited[1001] = {false, };
    for (vector<int> e : q)
    {
        if (merge(e[1], e[2]))
        {
            ans += e[0];
            visited[e[1]] = visited[e[2]] = true;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            ans = -1;
            break;
        }
    }
    cout << ans;
    return 0;
}

/*
struct 내부 초기화가 어째서인지 제대로 동작하지 않았다.
원인은 알 수 없었지만 메모리 용량을 위해서라도 그냥 백준에선 구조체 안 쓰는게 나을 것 같다.
*/