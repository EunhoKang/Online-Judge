#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N,k;
int cache[201][201];

int solve(int cnt, int sum){
    if(sum>N) return 0;
    if(cnt==k){
        if(sum==N)return 1;
        else return 0;
    }
    int & res=cache[cnt][sum];
    if(res!=-1) return res;
    res=0;
    for(int i=0;i<=N;++i) {
        res+=solve(cnt+1,sum+i);
        res%=1000000000;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N>>k;
    cout<<solve(0,0);
    return 0;
}
/*
1.한 개의 수를 여러번 셀 수 있고 뽑는 순서가 고려되기 때문에,
0~N까지 수들이 전부 매번 선택 대상이 된다.
2.함수 정의:
solve(cnt,sum)=cnt개의 수가 남았을 때 현재 정수합이 sum일 경우 
남은 정수들을 조합했을 때 합이 sum이 되는 경우의 수
점화식:
solve(cnt,sum)=solve(cnt+1,sum)+solve(cnt+1,sum+1)+...+solve(cnt+1,sum+N)
기저 사례:
sum==N && cnt==k => 1 출력
sum!=N && cnt==k => 0 출력
---
시간 초과.
수가 과도하게 커질 경우 미리 종료해 시간을 아끼도록 변경했다.
---
나머지로 뽑으라는 말을 안 들었다. 문제를 꼼꼼히 읽자.
*/