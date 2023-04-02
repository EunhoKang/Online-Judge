#include <bits/stdc++.h>
using namespace std;
const int INF = 2087654321;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int N, M;
int grid[50][50];
int visited[50][50];
int roomSize[2601];
vector<int> graph[2601];

bool onBorad(int y, int x)
{
    return (0 <= y) && (y < N) && (0 <= x) && (x < M);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> M >> N;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> grid[i][j];
        }
    }
    int roomCount = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(visited[i][j] == 0)
            {
                queue<vector<int>> q;
                q.push({i, j});
                roomCount++;
                visited[i][j] = roomCount;
                roomSize[roomCount] = 0;
                while(!q.empty())
                {
                    int y = q.front()[0];
                    int x = q.front()[1];
                    q.pop();
                    roomSize[roomCount]++;
                    for(int k = 0; k < 4; ++k)
                    {
                        int nextY = y + dy[k];
                        int nextX = x + dx[k];
                        if(onBorad(nextY, nextX) && visited[nextY][nextX] != roomCount)
                        {
                            if((grid[y][x] & 1 << k) == 0)
                            {
                                q.push({nextY, nextX});
                                visited[nextY][nextX] = roomCount;
                            }
                            else
                            {
                                if(visited[nextY][nextX] != 0 && find(graph[roomCount].begin(), graph[roomCount].end(), visited[nextY][nextX]) == graph[roomCount].end())
                                {
                                    graph[roomCount].push_back(visited[nextY][nextX]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << roomCount << '\n' << *max_element(roomSize + 1, roomSize + roomCount + 1) << '\n';
    int maxAdjustive = roomSize[1];
    for(int i = 1; i <= roomCount; ++i)
    {
        for(int j = 0; j < graph[i].size(); ++j)
        {
            maxAdjustive = max(maxAdjustive, roomSize[i] + roomSize[graph[i][j]]);
        }
    }
    cout << maxAdjustive;
    return 0;
}