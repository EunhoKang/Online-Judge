#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n;
int inorder[100000];
int postorder[100000];

void preorder(int inst, int ined, int ptst, int pted){
    if(inst==ined){
        cout<<inorder[inst]<<" ";
        return;
    }
    int root=postorder[pted];
    int rootidx=inst;
    while(inorder[rootidx]!=root)rootidx++;
    cout<<root<<" ";
    if(rootidx!=inst)preorder(inst,rootidx-1,ptst,ptst+rootidx-inst-1);
    if(rootidx!=ined)preorder(rootidx+1,ined,ptst+rootidx-inst,pted-1);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>inorder[i];
    for(int i=0;i<n;++i)cin>>postorder[i];
    preorder(0,n-1,0,n-1);
    return 0;
}

/*
1.4256번과 동일한 문제.
*/