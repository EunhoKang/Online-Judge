#include <iostream>
#include <stack>
using namespace std;

int A[5000] = { 0, };

bool isPelindrom(int start, int end)
{
    return start > end ? true : A[start] == A[end] ? isPelindrom(start + 1, end - 1) : false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    stack<int> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int cnt = 0;
    int start = 0;
    for (int i = 0; i < N; i++)
    {
        if (s.empty())
        {
			s.push(A[i]);
            start = i;
		}
        else
        {
            if (s.top() == A[i])
            {
				s.pop();
                if (s.empty())
                {
                    if (!isPelindrom(start, i))
                    {
						cnt = 0;
						break;
                    }
                    cnt++;
                }
			}
            else
            {
				s.push(A[i]);
			}
		}
	}
    cout << (cnt == 0 || !s.empty() ? -1 : cnt);
    return 0;
}

/*
* 짝수 펠린드롬 -> 스택에 넣으면 들어갔다 나오는 원소가 동일
* 펠린드롬 안에 다른 펠린드롬이 포함되어야 할 경우도 있기 때문에 펠린드롬인지는 다시 확인 필요
*/