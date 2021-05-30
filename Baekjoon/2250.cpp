#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n;
int root;
vector<int> tree[10001];
int isNotRoot[10001];
int inorder[101][10001];
int cnt=1;

void Inorder(int node,int level){
    if(tree[node][0]!=-1)Inorder(tree[node][0],level+1);
    inorder[level][cnt++]=1;
    if(tree[node][1]!=-1)Inorder(tree[node][1],level+1);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b,c;
        cin>>a>>b>>c;
        tree[a].push_back(b);
        tree[a].push_back(c);
        isNotRoot[b]++;
        isNotRoot[c]++;
    }
    for(int i=1;i<=n;++i){
        if(!isNotRoot[i]){
            root=i;
            break;
        }
    }
    Inorder(root, 1);
    int width=0;
    int height=0;
    for(int i=1;i<=30;++i){
        int left,right;
        int temp=1;
        while(!inorder[i][temp] && temp<=n)temp++;
        left=temp;
        temp=n;
        while(!inorder[i][temp] && temp>0)temp--;
        right=temp;
        if(width<right-left+1){
            height=i;
            width=right-left+1;
        }
    }
    cout<<height<<" "<<width;
    return 0;
}

/*
1.inorder 탐색을 활용한다. 레벨도 이 때 알 수 있다.
*/