#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int T;
int n;
int preorder[10001];
int inorder[10001];

void post(int prest, int preed, int inst, int ined,int cnt){
    if(inst==ined){
        cout<<inorder[inst]<<" ";
        return;
    }
    int root=preorder[prest];
    int temp=inst;
    while(inorder[temp]!=root)temp++;
    if(temp!=inst)post(prest+1,prest+temp-inst,inst,temp-1,cnt+1);
    if(temp!=ined)post(prest+1+temp-inst,preed,temp+1,ined, cnt+1);
    cout<<root<<" ";
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    for(int I=0;I<T;++I){
        cin>>n;
        for(int i=0;i<n;++i)cin>>preorder[i];
        for(int i=0;i<n;++i)cin>>inorder[i];
        post(0,n-1,0,n-1,0);
        cout<<'\n';
    }
    return 0;
}

/*
1.전위 순회에서 맨 앞의 값이 루트이다. 중위 순회에서 이전 값은모두 왼쪽 가지이고,
반대는 모두 오른쪽 가지이다.
전위 순회에서는 반드시 왼쪽 가지를 먼저 전부 탐색한 후 오른쪽 가지를 탐색한다.
따라서 중위 순회에서 왼쪽 가지 부분의 연속된 길이는
전위 순회에서 왼쪽 가지의 연속된 부분과 순서만 바뀌고 길이는 일치한다.
오른쪽 가지도 이와 마찬가지이다.
2.후위 순회를 해야 하므로, 루트를 가장 마지막에 출력한다.
그 이전에 왼쪽 가지와 오른쪽 가지는 또 하나의 트리로 생각할 수 있다.
앞에서 수행한 과정을 그대로 반복할 수 있으므로 이를 이용해 재귀로 함수를 설정한다.
3.post(int st, int ed)=st~ed까지 트리로 잡을 때, 이를 후위 탐색해 출력하는 함수
post(st,ed)=post(st,root-1)+post(root+1,ed)+root
if(st==ed) return st;
4.하위 트리가 생성되지 않는 경우는 예외로 처리해야 한다. 범위가 겹쳐버리기 때문
*/