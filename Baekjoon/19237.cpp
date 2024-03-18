#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct Grid {
    int x, y;
    int shark = 0;
    int smell = 0;
};

struct Shark {
	int x, y, dir;
	bool isDead = false;
};

int N, M, K;
int priority[401][5][4];
Shark current[401];
Grid map[20][20];

bool isEnd() 
{
    for (int i = 2; i <= M; ++i)
    {
        if (!current[i].isDead)
        {
            return false;
        }
	}
	return true;
}

bool onGrid(int x, int y) 
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int getDir(int dx, int dy)
{
    if (dx < 0 && dy == 0)
    {
		return 1;
	}
    else if (dx > 0 && dy == 0)
    {
		return 2;
	}
	else if (dx == 0 && dy < 0)
    {
        return 3;
    }
    else if (dx == 0 && dy > 0)
    {
		return 4;
	}
}

void printCurrent()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
			cout << map[i][j].shark << " ";
		}
		cout << endl;
	}
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            int temp;
            cin >> temp;
            if (temp != 0)
            {
				current[temp].x = i;
				current[temp].y = j;
			}
		}
	}
    for (int i = 1; i <= M; ++i)
    {
        int temp;
        cin >> temp;
        current[i].dir = temp;
    }
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
				cin >> priority[i][j][k];
			}
		}
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            map[i][j].x = i;
            map[i][j].y = j;
            map[i][j].smell = 0;
            map[i][j].shark = 0;
        }
    }
    for (int i = 1; i <= M; ++i)
    {
		map[current[i].x][current[i].y].shark = i;
		map[current[i].x][current[i].y].smell = K;
	}
    for (int t = 1; t <= 1000; ++t)
    {
        for (int i = 1; i <= M; ++i)
        {
			if (!current[i].isDead)
			{ 
                bool canMove[4] = { false, };
                Grid near[4];
                Grid target;
                bool findTarget = false;
                for (int j = 0; j < 4; ++j)
                {
                    int dir = priority[i][current[i].dir][j] - 1;
					int nx = current[i].x + dx[dir];
					int ny = current[i].y + dy[dir];
					if (onGrid(nx, ny))
					{
                        canMove[j] = true;
                        near[j] = map[nx][ny];
                    }
                }
                for (int j = 0; j < 4; ++j)
                {
                    if (canMove[j] && near[j].smell == 0)
                    {
						target = near[j];
                        findTarget = true;
						break;
					}
                }
                if (!findTarget)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (canMove[j] && near[j].shark == i)
                        {
						    target = near[j];
						    break;
					    }
                    }
                }
                current[i].dir = getDir(target.x - current[i].x, target.y - current[i].y);
                current[i].x = target.x;
                current[i].y = target.y;
            }
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (map[i][j].smell == 0)
                {
                    map[i][j].shark = 0;
                }
                else
                {
                    map[i][j].smell--;
                }
            }
        }
        for (int i = 1; i <= M; ++i)
        {
            if (!current[i].isDead)
            {
                if (map[current[i].x][current[i].y].smell == K && map[current[i].x][current[i].y].shark < i)
                {
					current[i].isDead = true;
				}
                else
                {
					map[current[i].x][current[i].y].shark = i;
					map[current[i].x][current[i].y].smell = K;
				}
			}
		}
        if (isEnd())
        {
			cout << t;
			return 0;
		}
    }
    cout << -1;
    return 0;
}

/*
* 상어 위치를 관리하는 구조체 배열과 맵을 관리하는 구조체 배열을 만들어서 풀었다.
* 우선순위 등도 배열로 저장해둬 코드를 간결화한다
*/