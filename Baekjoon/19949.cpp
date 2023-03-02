#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

int answer[10];
int guess[10];
int cnt = 0;

bool isPass()
{
    int score = 0;
    for(int i = 0; i < 10; ++i)
        if(answer[i] == guess[i])
            score++;
    return score >= 5;
}

void guessAnswer(int n, int pre, int prepre)
{
    if(n == 10)
    {
        if(isPass())
            cnt++;
        return;
    }
    for(int j = 1; j <= 5; ++j)
    {
        if(pre == prepre && j == prepre)
            continue;
        guess[n] = j;
        guessAnswer(n + 1, j, pre);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 0; i < 10; ++i)
        cin >> answer[i];
    guessAnswer(0, -1, -1);
    cout << cnt;

    return 0;
}

/*
완전탐색.
*/