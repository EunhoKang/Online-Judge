#include <bits/stdc++.h>
using namespace std;
const int INF = 2087654321;

int N;
int liquid[100000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> liquid[i];
    }
    int lo = 0;
    int hi = N - 1;
    int property = INF;
    int answer[2] = {lo, hi};
    while(lo < hi)
    {
        int sum = liquid[lo] + liquid[hi];
        if(abs(sum) <= property)
        {
            property = abs(sum);
            answer[0] = lo;
            answer[1] = hi;
        }
        if(sum < 0)
        {
            lo++;
        }
        else
        {
            hi--;
        }
    }
    cout << liquid[answer[0]] << " " << liquid[answer[1]];
    return 0;
}

/*
INF 변수 설정 잘하자. 
*/