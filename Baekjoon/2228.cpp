#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int arr[100];
int cache[101][51][2];
int INF=987654321;

int solve(int cnt, int sec, int isOpen){
    if(sec==m && !isOpen) return 0;
    if(cnt>=n) return -INF;
    int & res=cache[cnt][sec][isOpen];
    if(res!=-INF)return res;
    res=-INF-1;
    int sum=0;
    for(int i=cnt;i<n;++i){
        if(isOpen){
            sum+=arr[i];
            res=max(res,sum+solve(i+2,sec+1,!isOpen));
        }else{
            res=max(res,solve(i,sec,!isOpen));
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>arr[i];
    for(int i=0;i<101;++i)for(int j=0;j<51;++j)for(int k=0;k<2;++k)cache[i][j][k]=-INF;
    cout<<solve(0,0,0);
    return 0;
}
/*
1.합이 음수일 가능성도 있으므로 초기화할 때 주의해야 한다.
2.앞에서부터 하나씩 세면서 어느 시점에 구간을 시작하고 종료할지 결정한다.
구간이 종료될 때 바로 종료된 구간의 수를 세어 인수로 넘긴다.
3.함수 정의:
solve(cnt,sec,isOpen)=cnt번째 수에서 sec개의 구간을 정하고 구간을 isOpen에 따라 
열거나 닫아야 할 때, 앞으로 구간을 모두 결정해 만들 수 있는 최대값
점화식:
if !isOpen
solve(cnt,sec,isOpen)=max(solve(cnt,sec,!isOpen)~solve(cnt+n,sec,!isOpen))
else
solve(cnt,sec,isOpen)=max(Sumof(cnt,i)+solve(cnt+2,sec+1,!isOpen)~Sumof(cnt,i)+solve(cnt+n,sec+1,!isOpen))
기저 사례:
sec==m && cnt<n && !isOpen => return 0;
cnt>=n => return -INF;
---
다른 풀이에서는 인자를 둘만 받는 대신 구간합을 응용했다.
구간을 선택하지 않을 경우 i만 바꾸고,
구간을 선택할 경우 시작점을 현재로, 끝점까지 합을 구간합으로 구해서 더한다.
이때는 j도 1 뺀다.
https://velog.io/@asdsa2134/%EB%B0%B1%EC%A4%80-2228-%EA%B5%AC%EA%B0%84-%EB%82%98%EB%88%84%EA%B8%B0
*/