#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int grid[10][10];
int paper[5]={5,5,5,5,5};
int minPaper=INF;

bool AllCovered(vector<int> st, vector<int> ed, int mark){
    for(int i=st[0];i<=ed[0];++i){
        for(int j=st[1];j<=ed[1];++j){
            if(grid[i][j]!=mark)return false;
        }
    }
    return true;
}

void CoverArea(vector<int> st, vector<int> ed, int mark){
    for(int i=st[0];i<=ed[0];++i){
        for(int j=st[1];j<=ed[1];++j){
            grid[i][j]=mark;
        }
    }
}

void BackTracking(int n){
    if(n>minPaper)return;
    int targetY=-1,targetX=-1;
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            if(grid[i][j]==1){
                targetY=i;targetX=j;
                break;
            }
        }
        if(targetY!=-1)break;
    }
    if(targetY==-1){
        minPaper=min(minPaper,n);
        return;
    }
    for(int k=5;k>0;--k){
        if(paper[k-1]==0)continue;
        if(AllCovered({targetY,targetX},{targetY+k-1,targetX+k-1},1)
        && targetY+k-1<10 && targetX+k-1<10){
            CoverArea({targetY,targetX},{targetY+k-1,targetX+k-1},0);
            paper[k-1]--;
            BackTracking(n+1);
            CoverArea({targetY,targetX},{targetY+k-1,targetX+k-1},1);
            paper[k-1]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<10;++i)for(int j=0;j<10;++j)cin>>grid[i][j];
    BackTracking(0);
    if(minPaper>1000)cout<<-1;
    else cout<<minPaper;
    return 0;
}