#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
int S[101];
int cache[101];

int dp(int cnt){
    if(cnt>n)return 0;
    int & res=cache[cnt];
    if(res!=-1)return res;
    res=0;
    for(int i=cnt+1;i<=n;++i){
        if(S[i]>S[cnt]){
            res=max(res,dp(i)+1);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n;
    vector<pair<int,int>> line;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        line.push_back({a,b});
    }
    sort(line.begin(),line.end());
    for(int i=1;i<=n;++i){
        S[i]=line[i-1].second;
    }
    cout<<n-dp(0);
    return 0;
}

/*
1.모든 전깃줄을 없애본다.
브루트포스로 계산하면 2^100이므로 계산 범위를 한참 넘어간다.
2.만약 교차가 없다면 양쪽 전깃줄 끝은 증가수열을 이룬다.
쌍이 존재하는 LIS문제.
3.한쪽을 고정하여 기준으로 두고 다른 쪽에서 LIS를 만들어보자.
*/