#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int k;
            cin>>k;
            pq.push(-k);
        }
        while(pq.size()>i+1)pq.pop();
    }
    cout<<-pq.top();
    return 0;
}

/*
1.각 행마다 일정 양의 원소만 남기고 전부 빼내도 상관이 없다.
무조건 아래 행이 더 크기 때문에 최소한 더 큰 수를 놓칠 일은 없기 때문.
*/