#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,k;
int parent[1001];
int target;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(true){
        memset(parent,0,sizeof(parent));
        cin>>n>>k;
        if(n==0&&k==0)break;
        int parentNode;
        int last=-1;
        queue<int> next;
        next.push(-1);
        for(int i=0;i<n;++i){
            int node;
            cin>>node;
            if(node==k)target=i;
            if(node-last!=1){
                parentNode=next.front();
                next.pop();
            }
            next.push(i);
            parent[i]=parentNode;
            last=node;
        }
        if(parent[target]==-1 || parent[parent[target]]==-1){
            cout<<0<<'\n';
            continue;
        }
        int cnt=0;
        for(int i=0;i<n;++i){
            if(i==target)continue;
            if(parent[i]==-1 || parent[parent[i]]==-1)continue;
            if(parent[parent[i]]==parent[parent[target]] && parent[i]!=parent[target])cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}

/*
1.자식 찾는것보다 부모 찾는게 더 중요하다. 리프부터 루트로 탐색한다.
2.트리에서 층을 나눠 작업을 할 때 큐를 사용한다.
3.숫자는 트리 만들때만 쓰고 실제 수치는 이용하지 않으므로 
메모리 절약을 위해 인덱스로 변경한다.
*/