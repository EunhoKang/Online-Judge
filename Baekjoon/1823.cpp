#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int rice[2000];
int cache[2001][2001];

int solution(int left,int right) {
    if(left==right)return n*rice[left];
    int & res=cache[left][right];
    if(res!=-1) return res;
    return res=max((n-right+left)*rice[left]+solution(left+1,right),
    (n-right+left)*rice[right]+solution(left,right-1));
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>rice[i];
    memset(cache,-1,sizeof(cache));
    cout<<solution(0,n-1);
    return 0;
}
/*
1.양끝의 인덱스를 이용해 캐싱한다. 
이 둘을 이용하면 현재 몇번째 벼를 선택하고 있는지까지 알 수 있다.
2.
solution(left,right)=양 끝이 left,right번째일때 앞으로 얻을 수 있는 최대 수익
solution(left,right)=
max((n-right+left)*rice[left]+solution(left+1,right),
max((n-right+left)*rice[right]+solution(left,right-1))
left==right return n*rice[left];
*/