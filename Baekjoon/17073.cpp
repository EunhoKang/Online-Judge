#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,W;
vector<int> tree[500001];

int countLeaf(int node, int prev){
    if(tree[node].size()==1 && tree[node][0]==prev) return 1;
    int res=0;
    for(int i=0;i<tree[node].size();++i){
        if(tree[node][i]!=prev){
            res+=countLeaf(tree[node][i], node);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>W;
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        tree[b].push_back(a);
        tree[a].push_back(b);
    }
    cout << fixed;
    cout.precision(6);
    cout<<(double)W/countLeaf(1,0)<<'\n';
    return 0;
}

/*
1.모든 노드는 하나의 부모를 가지므로(루트 제외) 들어온 간선을 빼면 전부 나가는 간선.
2.각 물방울은 개별적으로 움직일때와 동시에 움직일 때 같은 결과값이 나온다.
들어오는 간선이 한개고 물방울의 고인 양이 경로에 영향을 주지 않기 때문.
3.그런데 여기서 물은 반드시 리프에만 쌓이고, 모든 리프에 도달할 확률의 합은 1,
기댓값의 총합은 반드시 W가 된다.
그러므로 리프 노드의 수만 세서 W로 나누면 답이 된다.
---
https://www.acmicpc.net/board/view/37116
소수점을 원하는 범위까지만 출력하고 싶을 경우 사용한다.
그냥 출력하면 자연 상수를 이용한 표현법으로 바뀌어 나온다!
*/