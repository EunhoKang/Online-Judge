#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
vector<pair<int,int>> sticks;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        sticks.push_back({a,b});
    }
    sort(sticks.begin(),sticks.end());
    stack<pair<int,int>> s;
    s.push({0,0});
    pair<int,int> high={0,0};
    int res=0;
    for(int i=0;i<n;++i){
        if(high.second<=sticks[i].second){
            while(s.top().second!=high.second){
                s.pop();
            }
            res+=s.top().second*(sticks[i].first-s.top().first);
            high=sticks[i];
        }
        s.push(sticks[i]);
    }
    pair<int,int> last={0,0};
    res+=high.second;
    while(s.top().second!=high.second){
        if(last.second<=s.top().second){
            res+=last.second*(last.first-s.top().first);
            last=s.top();
        }
        s.pop();
    }
    res+=last.second*(last.first-high.first);
    cout<<res;
}
/*
1. 스택을 활용한 스위핑 기법을 활용해보자.
막대를 정렬하고 이전 칸의 막대 길이와 비교하면서 부피를 나눠 구하면 된다.
2.스탯 안에 오목하게 만들 수 있는 막대가 등장해야 하는 경우 스택을 비워 그런 경우를 없앤다.
*/