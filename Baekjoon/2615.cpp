#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int grid[19][19];
int dx[4] = {1, 1, 0, -1};
int dy[4] = {0, 1, 1, 1};

bool onBoard( int x, int y ) {
    return 0 <= x && x < 19 && 0 <= y && y < 19;
}

bool isWin( int x, int y, int player ) {
    for(int i = 0; i < 4; ++i) {
        bool isLined = true;
        if( onBoard(x + dx[i] * -1, y + dy[i] * -1) && grid[x + dx[i] * -1][y + dy[i] * -1] == player ) continue;
        for(int j = 1; j < 5; ++j) {
            if( !( onBoard(x + dx[i] * j, y + dy[i] * j) && grid[x + dx[i] * j][y + dy[i] * j] == player ) ) {
                isLined = false;
                break;
            }
        }
        if(isLined){
            if(!onBoard(x + dx[i] * 5, y + dy[i] * 5) || grid[x + dx[i] * 5][y + dy[i] * 5] != player) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 0; i < 19; ++i) for(int j = 0; j < 19; ++j) cin >> grid[i][j];
    int state = 0;
    int lastX = -1, lastY = -1;
    bool isBreak = false;
    for(int j = 0; j < 19; ++j) {
        for(int i = 0; i < 19; ++i) {
            if(grid[i][j] != 0) {
                if(isWin(i, j, grid[i][j])) {
                    state = grid[i][j];
                    lastX = i; lastY = j;
                    isBreak = true;
                    break;
                }
            }
        }
        if(isBreak) break;
    }
    cout << state;
    if(state != 0) cout << '\n' << lastX + 1<< " " << lastY + 1;
    return 0;
}

/*
1.경우의 수가 적어 직접 돌리는 것이 가능하다.
2.한 줄에 6개가 넘어가는 입력을 빼야 하며, 첫 시작돌이 아닌 경우도 제외해야 한다.
3.ㅇ가장 왼쪽엥 있는 것부터 세야 하므로, 이중 for문 순서를 통상적인 방법에서 뒤집어야 한다.
*/