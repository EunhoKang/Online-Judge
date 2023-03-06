#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

unordered_map<string, bool> states;
string state = ".........";

bool isEnd(string line)
{
    for(int i = 0; i < 3; ++i)
    {
        if(line[i * 3] == line[i * 3 + 1] && line[i * 3] == line[i * 3 + 2] && line[i * 3] != '.')
        {
            return true;
        }
        if(line[i] == line[i + 3] && line[i] == line[i + 6] && line[i] != '.')
        {
            return true;
        }
    }
    if(line[0] == line[4] && line[0] == line[8] && line[0] != '.')
    {
        return true;
    }
    if(line[6] == line[4] && line[6] == line[2] && line[6] != '.')
    {
        return true;
    }
    for(int i = 0; i < 9; ++i)
    {
        if(line[i] == '.')
        {
            return false;
        }
    }
    return true;
}

void makeStates(int n)
{
    if(isEnd(state))
    {
        states.insert(make_pair(state, true));
        return;
    }
    else if(n >= 9)
    {
        return;
    }
    for(int i = 0; i < 9; i++)
    {
        if(state[i] == '.')
        {
            state[i] = (n % 2 == 0 ? 'X' : 'O');
            makeStates(n + 1);
            state[i] = '.';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    makeStates(0);
    while(true)
    {
        string temp;
        cin >> temp;
        if(temp == "end")
        {
            break;
        }
        if(states.count(temp))
        {
            cout << "valid" << '\n';
        }
        else
        {
            cout << "invalid" << '\n';
        }
    }
    return 0;
}

/*
모든 경우의 수를 만들어봄으로써 해결한다.
*/