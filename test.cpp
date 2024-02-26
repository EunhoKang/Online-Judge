#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    string str;
    cin >> N >> str;
    int st = 0;
    int ed = 0;
    int cnt = 0;
    int len = 0;
    unordered_map<char, int> m;
    int answer = 0;
    while(ed < str.length())
    {
        if(m.count(str[ed]))
        {
            m[str[ed]]++;
            len++;
            answer = max(answer, len);
            ed++;
        }
        else if (cnt < N)
        {
            m[str[ed]] = 1;
            cnt++;
            len++;
            answer = max(answer, len);
            ed++;
        }
        else 
        {
            m[str[st]]--;
            if(m[str[st]] == 0)
            {
                m.erase(str[st]);
                cnt--;
            }
            len--;
            st++;
        }
    }
    cout << answer;
}