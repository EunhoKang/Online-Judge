#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,root;
vector<int> tree[200001];
map<vector<int>,int> len;
int visited[200001];
int gigaNode;

int GetGiGa(int node){
    if(tree[node].size()>=3 || (tree[node].size()==1 && visited[tree[node][0]])){
        gigaNode=node;
        return 0;
    }
    if(tree[node].size()==2 && node==root){
        gigaNode=node;
        return 0;
    }
    for(int i=0;i<tree[node].size();++i){
        if(!visited[tree[node][i]]){
            visited[node]=1;
            return len[{node,tree[node][i]}]+GetGiGa(tree[node][i]);
        }
    }
    return 0;
}

int GetLeaf(int node){
    if(tree[node].size()==1)return 0;
    int res=0;
    for(int i=0;i<tree[node].size();++i){
        if(!visited[tree[node][i]]){
            visited[node]=1;
            res=max(res,len[{node,tree[node][i]}]+GetLeaf(tree[node][i]));
            visited[node]=0;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>root;
    for(int i=0;i<n-1;++i){
        int a,b,c;
        cin>>a>>b>>c;
        tree[a].push_back(b);
        tree[b].push_back(a);
        len[{a,b}]=c;
        len[{b,a}]=c;
    }
    int giga=GetGiGa(root);
    cout<<giga<<" "<<GetLeaf(gigaNode);
    return 0;
}

/*
1.공간 복잡도를 줄이기 위해 간선 길이는 따로 저장한다.
각 노드로 향하는 간선은 유일함을 이용한다.
---
2.무방향 간선이라 따로 다 처리해줘야한다.
---
3.기둥을 구할 때 이어진 노드 수에 따라 경우를 복잡하게 나눠야 한다.
*/