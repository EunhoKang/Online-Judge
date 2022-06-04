#include <bits/stdc++.h>
#define ll long long
using namespace std;
//int INF=2100000000;
int INF=1000000000;

int n,m;
int single[2][1000];
int cache[1000][1000];

int dp(int i, int j){
    if(n>=m){if(j==m)return 0;}
    else {if(i==n)return 0;}
    int & res=cache[i][j]; 
    if(res!=-1)return res;
    res=INF;
    if(n>=m){
        for(int next=i;next<n;++next){
            res=min(res,dp(next+1,j+1)+abs(single[0][next]-single[1][j]));
        }
    }else{
        for(int next=j;next<m;++next){
            res=min(res,dp(i+1,next+1)+abs(single[1][next]-single[0][i]));
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>single[0][i];
    for(int i=0;i<m;++i)cin>>single[1][i];
    sort(single[0],single[0]+n);
    sort(single[1],single[1]+m);
    memset(cache,-1,sizeof(cache));
    cout<<(dp(0,0));
}

/*
1.정렬을 한 후 계산하면 이전 값을 탐색할 필요가 없다. 시간복잡도를 줄일 수 있다.
*/