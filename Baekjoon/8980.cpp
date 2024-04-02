#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct order
{
    int start, end, price;

    order(int st, int ed, int pr)
    {
        start = st;
        end = ed;
        price = pr;
    }

    bool operator < (const order& o2)
    {
        if (start != o2.start)
        {
            return start > o2.start;
        }
        else if (end != o2.end)
        {
            return end > o2.end;
        }
        else
        {
            return price > o2.price;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M, C;
    cin >> N >> M >> C;
    vector<order> v;
    for (int i = 0; i < C; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(order(a, b, c));
    }
    sort(v.begin(), v.end());
    int burden[2001] = { 0, };
    for (int j = 1; j <= N; ++j)
    {
        burden[j] = M;
    } 
    long long result = 0;
    for (int i = 0; i < C; ++i)
    {
        int smallest = v[i].price;
        for (int j = v[i].start; j < v[i].end; ++j)
        {
            smallest = min(smallest, burden[j]);
        }
        for (int j = v[i].start; j < v[i].end; ++j)
        {
            burden[j] -= smallest;
        }
        result += smallest;
    }
    cout << result;
    return 0;
}

/*
* 회의실 문제의 변형버전. 무조건 일찍 시작해 일찍 끝나는 것을 먼저 선택하는 게 좋다.
*/