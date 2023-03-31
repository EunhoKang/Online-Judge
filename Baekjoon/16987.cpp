#include <bits/stdc++.h>
using namespace std;
const int INF = 2087654321;

int N;
int W[8], H[8];
int cnt = 0;
int answer = 0;

void eggshot(int n)
{
    if(n == N)
    {
        answer = max(answer, cnt);
        return;
    }
    if(H[n] <= 0)
    {
        eggshot(n + 1);
        return;
    }
    bool eggtouch = false;
    for(int i = 0; i < N; ++i)
    {
        if(i == n || H[i] <= 0)
        {
            continue;
        }
        eggtouch = true;
        H[n] -= W[i];
        H[i] -= W[n];
        int broken = (H[n] <= 0 ? 1 : 0) + (H[i] <= 0 ? 1 : 0);
        cnt += broken;
        eggshot(n + 1);
        cnt -= broken;
        H[i] += W[n];
        H[n] += W[i];
    }
    if(!eggtouch) eggshot(n + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> H[i] >> W[i];
    }
    eggshot(0);
    cout << answer;
    return 0;
}

/*
완성된 재귀문에서 예외 케이스에 대해 한번씩 시뮬레이션해본다.
*/