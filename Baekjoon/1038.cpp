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

/*
등장하는 숫자의 개수를 미리 세어 연산 수를 줄일 수 있는 문제.
미리 이항 계수로 등장하는 숫자의 개수를 세어두고, 이를 이용해 N번째 수를 완성한다.
*/