#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

int N, K;
int matchTable[10][10];
int bigData[3][20];

int isWin(int match, int win, int canPlay, int A, int B)
{
    if(win >= K)
        return 1;
    if(match == 20)
        return 0;
    if(!canPlay)
        return 
    for(int i = 1; i <= N; ++i)
    {
        if(matchTable[bigData[]])
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            cin >> matchTable[i][j];
    for(int i = 0; i < 20; ++i)
        cin >> bigData[1][i];
    for(int i = 0; i < N; ++i)
        cin >> bigData[2][i];
    return 0;
}

/*
1.그리디 활용 문제. 스케줄링이므로 빨리 끝내야 하는 것부터 세면 된다.
*/