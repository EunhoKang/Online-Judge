#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

int N;
vector<pair<long long, long long>> meeting;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        long long st, ed;
        cin >> st >> ed;
        meeting.push_back(make_pair(ed, st));
    }
    sort(meeting.begin(), meeting.end());
    int count = 1;
    long long lastTime = meeting[0].first;
    for (int i = 1; i < N; ++i)
    {
        if (lastTime <= meeting[i].second)
        {
            lastTime = meeting[i].first;
            count++;
        }
    }
    cout << count;
    return 0;
}

/*
잘 알려진 그리디 문제로 끝나는 시간이 빠른 순으로 선택을 진행한다.
*/