#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N;
int cache[1000001] = {INF, };
int path[1000001];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    fill(cache, cache + N + 1, INF);
    cache[1] = 0;
    for(int i = 1; i <= N; ++i)
    {
        if(i * 3 <= N && cache[i * 3] > cache[i] + 1)
        {
            cache[i * 3] = cache[i] + 1;
            path[i * 3] = i;
        }
        if(i * 2 <= N && cache[i * 2] > cache[i] + 1)
        {
            cache[i * 2] = cache[i] + 1;
            path[i * 2] = i;
        }
        if(i + 1 <= N && cache[i + 1] > cache[i] + 1)
        {
            cache[i + 1] = cache[i] + 1;
            path[i + 1] = i;
        }
    }
    cout << cache[N] << '\n';

    while(N){
        cout << N << ' ';
        N = path[N];
    }
    return 0;
}

/*
DP는 탑다운 방식으로 할 경우 메모리 초과가 발생할 수 있다.
*/