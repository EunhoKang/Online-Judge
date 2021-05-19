#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int s[2000];
int questionS[1000000];
int questionE[1000000];
int cache[2000][2000];

int solution(int left,int right) {
    if(left>=right)return 1;
    int & res=cache[left][right];
    if(res!=-1) return res;
    return res=(s[left]==s[right])&&solution(left+1,right-1);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<n;++i)cin>>s[i];
    cin>>m;
    for(int i=0;i<m;++i)cin>>questionS[i]>>questionE[i];
    for(int i=0;i<m;++i)cout<<solution(questionS[i]-1,questionE[i]-1)<<'\n';
    return 0;
}
/*
1.펠린드롬을 확인하는 함수를 만들고 동적계획법으로 전부 캐싱한다.
2.
solution(left,right)=어떤 수열에서 left부터 right까지 펠린드롬인지 판별
solution(left,right)=(s[left]==s[right])&&solution(left+1,right-1)
left>=right return true;
*/