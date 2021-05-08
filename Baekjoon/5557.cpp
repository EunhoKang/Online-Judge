#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int numbers[100];
long long cache[100][1001];

long long solve(int cnt, int sum){
    if(sum<0 || sum>20) return 0;
    if(cnt==n-2 && sum==numbers[n-1]) return 1;
    long long & res=cache[cnt][sum];
    if(res!=-1) return res;
    return res=solve(cnt+1,sum+numbers[cnt+1])+solve(cnt+1,sum-numbers[cnt+1]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n;
    for(int i=0;i<n;++i)cin>>numbers[i];
    cout<<solve(0,numbers[0]);
    return 0;
}
/*
1.등호는 맨 마지막으로 위치 고정, 나머지는 숫자 사이에 +혹은-
모든 순간마다 음수가 나오는지 판별하여야 한다.
3.함수 정의:
solve(cnt,sum)=현재 cnt번째 등호를 처리해야 하고 현재까지 좌변의 값이 sum일 때,
등식을 만족시키는 조합의 수
점화식:
solve(cnt,sum)=solve(cnt+1,sum-S[cnt])+solve(cnt+1,sum+S[cnt])
기저 사례:
sum<0 => 0 반환
cnt==n-1 => 등식 성립시 1 반환
*/