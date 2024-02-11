#include <iostream>
using namespace std;

int N;

int bino(int n, int k)
{
    if (n == 0 || k == 0 || n == k) return 1;
    return bino(n - 1, k - 1) + bino(n - 1, k);
}

void findNumber(int digit, int k)
{
    int last = 10;
    for (int i = 0; i < digit; i++)
    {
        for (int j = digit - i - 1; j < last; j++)
        {
            int temp = bino(j, digit - i - 1);
            if (temp < k)
            {
                k -= temp;
            } else {
                last = j;
                cout << j;
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    N++;
    int cnt = 1;
    while(cnt <= 10)
    {
        int temp = bino(10, cnt);
        if (N > temp) {
            if (cnt == 10) {
                cout << -1;
                return 0;
            }
            cnt ++;
            N -= temp;
        }else {
            break;
        }
    }
    findNumber(cnt, N);
    return 0;
}