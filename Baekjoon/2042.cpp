#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, M, K;
long long A[1000001];
struct Fenwick
{
    vector<long long> segtree;
    Fenwick(int n) : segtree(n + 1) {}

    long long sum(int pos) 
    {
        long long ret = 0;
        while (pos > 0) 
        {
            ret += segtree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos, long long val) 
    {
        while (pos < segtree.size())
        {
            segtree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M >> K;
    Fenwick fw(N);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        fw.add(i, A[i]);
    }  
    for (int i = 0; i < M + K; ++i)
    {
        int a;
        long long b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            fw.add(b, c - (fw.sum(b) - fw.sum(b - 1)));
        }
        else
        {
            if(b > c)
                swap(b, c);
            cout << fw.sum(c) - fw.sum(b - 1) << '\n';
        }
    }
    return 0;
}
/*
변경이 잦은 구간합 문제 -> 펜윅 트리
*/