#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int KN, OX, OY;
int N, X, Y;
int cnt = 1;
int grid[128][128];

void printTile() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            cout << grid[i][j] << " ";
        cout << '\n';
    }
}

void LtrominoTiling(int x, int y, int outX, int outY, int gridSize) {
    bool isOutUp = outX < x + gridSize / 2;
    bool isOutLeft = outY < y + gridSize / 2;
    if( !( isOutUp && isOutLeft ) ) grid[ x + gridSize / 2 - 1 ][ y + gridSize / 2 - 1 ] = cnt;
    if( !( isOutUp && !isOutLeft ) ) grid[ x + gridSize / 2 - 1 ][ y + gridSize / 2 ] = cnt;
    if( !( !isOutUp && !isOutLeft ) ) grid[ x + gridSize / 2 ][ y + gridSize / 2 ] = cnt;
    if( !( !isOutUp && isOutLeft ) ) grid[ x + gridSize / 2 ][ y + gridSize / 2 - 1 ] = cnt;
    cnt++;
    if( gridSize >= 4 ){
        if( !( isOutUp && isOutLeft ) ) 
            LtrominoTiling( x, y, x + gridSize / 2 - 1, y + gridSize / 2 - 1, gridSize / 2);
        else
            LtrominoTiling( x, y, outX, outY, gridSize / 2);
        if( !( isOutUp && !isOutLeft ) ) 
            LtrominoTiling( x, y + gridSize / 2, x + gridSize / 2 - 1, y + gridSize / 2, gridSize / 2);
        else
            LtrominoTiling( x, y + gridSize / 2, outX, outY, gridSize / 2);
        if( !( !isOutUp && !isOutLeft ) )
            LtrominoTiling( x + gridSize / 2, y + gridSize / 2, x + gridSize / 2, y + gridSize / 2, gridSize / 2);
        else    
            LtrominoTiling( x + gridSize / 2, y + gridSize / 2, outX, outY, gridSize / 2);
        if( !( !isOutUp && isOutLeft ) )
            LtrominoTiling( x + gridSize / 2, y, x + gridSize / 2, y + gridSize / 2 - 1, gridSize / 2);
        else    
            LtrominoTiling( x + gridSize / 2, y, outX, outY, gridSize / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset( grid, -1, sizeof(grid) );
    cin >> KN >> OX >> OY;
    N = pow( 2, KN ); X = N - OY; Y = OX - 1;
    LtrominoTiling( 0, 0, X, Y, N);
    printTile();
    return 0;
}

/*
1.사분면을 계속 4등분해가며 분할정복한다.
2.기저 사례는 변 길이 2인 정사각형이 나올때.
3.L트로미노 타일링 증명을 활용.
*/