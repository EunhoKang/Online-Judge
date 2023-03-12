#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int H, W;
int block[500];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> H >> W;
    for(int i = 0; i < W ; ++i)
    {
        cin >> block[i];
    }
    stack<vector<int>> st;
    st.push({block[0], 0});
    int answer = 0;
    for(int i = 1; i < W ; ++i)
    {
        if(st.top()[0] <= block[i])
        {
            while(st.size() > 1 && st.top()[0] <= block[i])
            {
                vector<int> last = st.top();
                st.pop();
                if(last[0] < st.top()[0])
                {
                    answer += (i - st.top()[1] - 1) * (min(block[i], st.top()[0]) - last[0]);
                }
            }
        }
        st.push({block[i], i});
    }
    cout << answer;
    return 0;
}

/*
반례가 생각했던 것보다 너무 많았다.
좀 더 일반적인 경우에 대해 생각해보는 연습이 필요하다.
*/