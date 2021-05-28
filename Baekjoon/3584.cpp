#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int T;
int n;
int a,b;
int root;
int parentNode[10001];
int isNotRoot[10001];
int answer;
int maxcnt;

int solve(int left, int right, int cnt){
    cout<<left<<"||"<<right<<" "<<cnt<<" "<<answer<<"-"<<cnt<<'\n';
    if(left==right){
        if(cnt<=maxcnt){
            answer=left;
            maxcnt=cnt;
            return cnt;
        }
        else return 0;
    }
    if(parentNode[left]==0)return solve(left,parentNode[right],cnt+1);
    if(parentNode[right]==0)return solve(parentNode[left],right,cnt+1);
    return max(solve(left,parentNode[right],cnt+1),solve(parentNode[left],right,cnt+1));
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    for(int I=0;I<T;++I){
        cin>>n;
        maxcnt=987654321;
        memset(isNotRoot,0,sizeof(isNotRoot));
        memset(parentNode,0,sizeof(parentNode));
        for(int i=0;i<n-1;++i){
            int parent,child;
            cin>>parent>>child;
            parentNode[child]=parent;
            isNotRoot[child]++;
        }
        for(int i=1;i<=n;++i){
            if(isNotRoot[i]==0){
                root=i;
                break;
            }
        }
        cin>>a>>b;
        solve(a,b,0);
        cout<<answer<<'\n';
    }
    return 0;
}

/*
1.아래서부터 위로 올라가는 방식을 택한다.
무조건 깊이가 더 깊은 것이 가장 가까운 조상이다.
2.만약 루트 노드가 주어지지 않는다면 직접 찾아야 한다.
간선 목록이 주어질 때 노드의 등장 횟수를 세어 노드나 리프의 여부를 판별할 수 있다.
루트 노드는 자식 노드로 등장하지 않으며, 
리프 노드는 부모 노드로 등장하지 않고 등장 횟수가 단 한번이다.
*/