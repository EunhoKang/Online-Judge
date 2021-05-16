#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int s[5000];
int cache[5000][5000];

int solve(int left,int right){
    if(left>=right) return 0;
    int & res = cache[left][right];
    if(res!=-1)return res;
    res=0;
    if(s[left]==s[right]) return res=solve(left+1,right-1);
    else return res=1+min(solve(left,right-1),solve(left+1,right));
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>s[i];
    memset(cache,-1,sizeof(cache));
    cout<<solve(0,n-1)<<'\n';
    return 0;
}
/*
1.부분 구조를 만드는 데에서 시작하자.
펠린드롬은 양 끝의 원소를 지워도 그대로 펠린드롬이다.
isPel(l,r)=s의 l~r번째 원소를 원소로 갖는 부분수열이 펠린드롬인지 반환
isPel(l,r)=if(l<r && s[l]==s[r])isPel(l+1,r-1)
l>=r return true;
이걸 펠린드롬을 만드는 함수로 바꾸면
makePel(l,r)=s의 l~r번째 원소를 원소로 갖는 부분수열을 펠린드롬으로 만드는데 추가로 필요한 최소 원소 개수 반환
makePel(l,r)=if(l<r && s[l]==s[r])isPel(l+1,r-1)
else min(isPel(l,r-1),isPel(l+1,r))
l>=r return 0;
*/