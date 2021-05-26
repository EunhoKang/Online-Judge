#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n;
vector<int> tree[51];
int erase;
int root;

int solve(int node){
    if(tree[node].empty()) return 1;
    int res=0;
    bool onlyerased=false;
    for(int i=0;i<tree[node].size();++i){
        if(tree[node][i]!=erase){
            res+=solve(tree[node][i]);
        }else{
            onlyerased=true;
        }
    }
    if(res==0 && onlyerased) res+=1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        if(temp!=-1)tree[temp].push_back(i);
        else root=i;
    }
    cin>>erase;
    if(erase==root) cout<<0;
    else cout<<solve(root);
}

/*
1.부모에 의해 자식 노드를 무시해야 하므로 그래프와 비슷하게 구현한다.
2.이후 순회하면서 지운 노드만 예외처리하면서 자식이 없는 노드 수를 세면 된다.
지운 노드가 리프노드일 수도 있으므로 최우선으로 예외처리한다.
---
3.지운 이후 트리의 구조가 변할 경우를 고려해야 한다.
일직선으로 이어져 있는 경우를 예로, 유일한 자식이 지운 노드일 경우
해당 노드가 리프 노드가 되어야 한다.
또한 루트를 지우는 경우 무조건 0을 반환한다.
*/