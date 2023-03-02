#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
int grid[1000][1000];

bool checkAllRipen()
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(grid[i][j] == 0)
                return false;
    return true;
}

bool onGrid(int x, int y)
{
    return 0 <= x && x < m && 0 <= y && y < n;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    queue<vector<int>> q;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 1)
                q.push({i, j, 0});
        }
    int current = 0;
    while(!q.empty())
    {
        vector<int> node = q.front();
        q.pop();
        current = node[2];
        for(int k = 0; k < 4; ++k)
        {
            int nextX = node[0] + dx[k];
            int nextY = node[1] + dy[k];
            if(onGrid(nextX, nextY) && grid[nextX][nextY] == 0)
            {
                grid[nextX][nextY] = 1;
                q.push({nextX, nextY, node[2] + 1});
            }
        }
    }
    if(!checkAllRipen())
        cout << -1;
    else
        cout << current;
    return 0;
}

/*
1.BSF.
2.visit배열은 필요없다. 익은 것은 방문하지 않기 떄문.
3.방문 전에 미리 익혀서 중복 방문을 없애는 것이 중요하다.
*/