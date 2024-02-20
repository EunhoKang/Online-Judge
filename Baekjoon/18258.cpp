#include <iostream>
using namespace std;

int N;
int queue[2000000];
int fr = 0;
int bk = -1;

int count()
{
    return bk - fr + 1;
}

void push(int x)
{
    queue[++bk] = x;
}

void pop()
{
    if (count() == 0)
        cout << -1 << "\n";
    else
        cout << queue[fr++] << "\n";
}

void size()
{
    cout << count() << "\n";
}

void empty()
{
    cout << (count() == 0 ? 1 : 0) << "\n";
}

void front()
{
    if (count() == 0)
        cout << -1 << "\n";
    else
        cout << queue[fr] << "\n";
}

void back()
{
    if (count() == 0)
        cout << -1 << "\n";
    else
        cout << queue[bk] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (cmd == "pop")
            pop();
        else if (cmd == "size")
            size();
        else if (cmd == "empty")
            empty();
        else if (cmd == "front")
            front();
        else if (cmd == "back")
            back();
    }
}

/*
단순 구현문제.
*/