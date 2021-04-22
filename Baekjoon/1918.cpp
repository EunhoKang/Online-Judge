#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    stack<char> op;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cout << s[i];
        }
        else
        {
            if (s[i] == '(')
                op.push(s[i]);
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!op.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
        }
    }
    while (!op.empty())
    {
        cout << op.top();
        op.pop();
    }

    return 0;
}

/*
1. 후위 연산은 말 그대로 우선 순위가 높은 순서로 계산식을 쌓는 것이다.
애초에 후위 연산 자체가 스택 방식이므로 변환도 스택을 이용한다.

2.피연산자는 무조건 뽑아낸다.(연산자보다 피연산자 우선)
)가 입력되면 (가 나올때까지 연산자를 모두 뽑아낸다.(우선적으로 계산되어야 하기 때문)
+,-가 입력되면 +,-,*,/가 나올때까지 뽑아낸다. (이전 항을 ()로 묶을 수 있음)
*,/가 입력되면 +,-,*,/가 나올때까지 뽑아낸다. (이전 항을 ()로 묶을 수 있음)

https://donggoolosori.github.io/2020/10/19/boj-1918/
*/