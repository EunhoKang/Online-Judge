#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,q;
vector<int> tree[100000];
vector<int> question[100000];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cin>>q;
    for(int i=0;i<q;++i){
        int a,b;
        cin>>a>>b;
        if(a==2)cout<<"yes\n";
        else if(tree[b].size()>1)cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}

/*
1.해당 노드가 단절점인 경우, 맨 끝에 있는 노드여야 한다.
1)리프 노드이거나
2)자식이 단 하나인 루트 노드
2.트리는 모든 노드로 가는 경로가 유일하기 때문에 모든 간선이 단절선이다.
---
그냥 노드가 둘 이상 붙으면 단절점이다. 트리이자 그래프임을 응용.
https://tunafish78.tistory.com/44
*/