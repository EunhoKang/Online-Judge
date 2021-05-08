#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T,n;
vector<vector<int>> coin;
int cache[101][10001];

int solve(int cnt, int left){
    if(cnt==n) {
        if(left==0)return 1;
        else return 0;
    }
    if(left<0) return 0;
    int & res=cache[cnt][left];
    if(res!=-1)return res;
    res=0;
    for(int i=0;i<=coin[cnt][1];++i){
        res+=solve(cnt+1,left-coin[cnt][0]*i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>T;
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        coin.push_back({a,b});
    }
    cout<<solve(0,T);
    return 0;
}
/*
1.완전 탐색을 진행할 경우 1000^100이라는 말도 안되는 수를 계산해야 한다.
2.함수 정의:
solve(cnt,left)=cnt번째 동전 종류 이전의 동전들을 모두 선택했고 left원이 남았을 때
남은 동전들을 선택하여 left==0으로 하는 경우의 수
점화식:

기저 사례:
left==0 => return 1;
left<0 || cnt>=n => return 0;
*/