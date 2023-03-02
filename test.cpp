#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
int grid[20][20];
int visited[20][20];
int maxProfit = 0;

bool onGrid(int x, int y)
{
    return 0 <= x && x < m && 0 <= y && y < n;
}

void getProfit()
{
    int visited[20][20] = {0, };
    int profit = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(grid[i][j] == 2 && visited[i][j] == 0)
            {
                int cnt = 1;
                queue<vector<int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                bool flag = true;
                while(!q.empty())
                {
                    vector<int> node = q.front();
                    q.pop();
                    for(int k = 0; k < 4; ++k)
                    {
                        int nextX = node[0] + dx[k];
                        int nextY = node[1] + dy[k];
                        if(onGrid(nextX, nextY) && visited[nextX][nextY] == 0)
                        {
                            if(grid[nextX][nextY] == 0)
                                flag = false;
                            else if(grid[nextX][nextY] == 2)
                            {
                                visited[nextX][nextY] = 1;
                                q.push({nextX, nextY});
                                cnt++;
                            }
                        }
                    }
                }
                if(flag)
                    profit = max(profit, cnt);
            }
    maxProfit = max(maxProfit, profit);
}

void getGameState()
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(grid[i][j] == 0)
            {
                grid[i][j] = 1;
                for(int a = i; a < n; ++a)
                    for(int b = j + 1; b < m; ++b)
                        if(grid[a][b] == 0)
                        {
                            grid[a][b] = 1;
                            getProfit();
                            grid[a][b] = 0;
                        }
                grid[i][j] = 0;
            }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];
    getGameState();
    cout << maxProfit;
    return 0;
}

/*
1.무향 밀집 그래프이다.
2.N번 논에 우물을 판다 -> N번 노드에 가중치 Wi인 간선으로 연결된 우물 노드를 연결한다
우물과 연결된 간선은 반드시 하나는 있어야 하므로, 하나는 일단 무조건 간선에 추가한다.
이후 나머지 간선들로 정점을 최소한의 비용으로 연결한다. -> 최소 스패닝 트리
*/