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
    sort(sticks.begin(),sticks.end());//스택을 위치순으로 정렬
    stack<pair<int,int>> s;
    s.push({0,0});
    pair<int,int> high={0,0};
    int res=0;
    for(int i=0;i<n;++i){
        if(high.second<=sticks[i].second){//(2) 왼쪽 계산. 만약 현재까지 가장 높은 막대보다 높은 막대가 등장하면
            while(s.top().second!=high.second){//사이에 존재하는 막대는 없는거나 마찬가지이므로 전부 제거
                s.pop();
            }
            res+=s.top().second*(sticks[i].first-s.top().first);//넓이 미리 계산
            high=sticks[i];//가장 높은 막대 갱신
        }
        s.push(sticks[i]);//가장 높은 막대가 아니면 그대로 스택에 저장
    }
    pair<int,int> last={0,0};
    res+=high.second;//(1) 가장 높은 막대를 우선 넓이로 계산
    while(s.top().second!=high.second){//(3) 오른쪽 넓이. 왼쪽과 반대로 모든 막대를 빼면서 더 높은 막대가 나올때까지 넓이를 계산한다.
        if(last.second<=s.top().second){//더 높은 막대가 나오면 이를 기준으로 변경한다.
            res+=last.second*(last.first-s.top().first);
            last=s.top();
        }
        s.pop();
    }
    res+=last.second*(last.first-high.first);//마지막으로 (1)의 막대와 오른쪽 구간에서 가장 높은 막대 사이의 넓이 계산.
    cout<<res;
}
/*
1. 스택을 활용한 스위핑 기법을 활용해보자.
막대를 정렬하고 이전 칸의 막대 길이와 비교하면서 부피를 나눠 구하면 된다.
(1)가장 높은 부분의 막대 길이 (2)왼쪽 공간 (3)오른쪽 공간
2.스탯 안에 오목하게 만들 수 있는 막대가 등장해야 하는 경우 스택을 비워 그런 경우를 없앤다.
*/