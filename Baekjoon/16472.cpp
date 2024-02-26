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

/*
N < 100000 이므로 브루트포스 불가능, 이전 알파벳 정보를 알아야 하므로 DP 힘듬.
연속된 문자열을 구해야 하므로 시작과 끝만 잡으면 되므로 투 포인터를 활용했다.
알파벳 개수는 unordered_map을 활용해 구했다.
이 경우 시간복잡도는 O(2NlogN)이다.
*/