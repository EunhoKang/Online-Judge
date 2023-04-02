#include <bits/stdc++.h>
using namespace std;
const int INF = 2087654321;

int N;
int liquids[5000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> liquids[i];
    }
    sort(liquids, liquids + N);
    int answer[3] = {0, 0, 0};
    long long sumabs = 3000000001ll;
    for(int i = 0; i < N; ++i)
    {
        int pointer[2] = {0, N - 1};
        while(pointer[0] < pointer[1])
        {
            long long res = 0;
            if(pointer[0] != i && pointer[1] != i)
            {
                res = (long long)liquids[pointer[0]] + liquids[pointer[1]] + liquids[i];
                if(sumabs > abs(res))
                {
                    sumabs = abs(res);
                    answer[0] = pointer[0];
                    answer[1] = pointer[1];
                    answer[2] = i;
                    cout << sumabs << '\n';
                }
            }
            if(res < 0)
            {
                pointer[0]++;
            }
            else
            {
                pointer[1]--;
            }
        }
    }
    sort(answer, answer + 3);
    cout << liquids[answer[0]] << ' ' << liquids[answer[1]] << ' ' << liquids[answer[2]];
    return 0;
}

/*
오버플로우 발생 시 계산에 유의해야 한다.
*/