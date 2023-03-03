#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

int N;
vector<int> ST[1000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        ST[i] = {b, a};
    }
    sort(ST, ST + N);
    int lo = 0;
    int hi = 1000000;
    int mid;
    int answer = -1;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        int t = mid;
        bool flag = true;
        for(int i = 0; i < N; ++i)
        {
            t += ST[i][1];
            if(t > ST[i][0])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            lo = mid + 1;
            answer = max(answer, mid);
        }
        else
            hi = mid - 1;
    }
    cout << answer;
    return 0;
}

/*
1.그리디 활용 문제. 스케줄링이므로 빨리 끝내야 하는 것부터 세면 된다.
*/