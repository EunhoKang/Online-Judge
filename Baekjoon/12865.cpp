#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,W;
int weight[100];
int price[100];
int cache[101][1000001];

int solve(int cnt, int w){
    if(w<0) return -987654321;
    if(cnt==n) return 0;
    int & res=cache[cnt][w];
    if(res!=-1) return res;
    return res=max(price[cnt]+solve(cnt+1,w-weight[cnt]),solve(cnt+1,w));
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n>>W;
    for(int i=0;i<n;++i)cin>>weight[i]>>price[i];
    cout<<solve(0,W);
    return 0;
}
/*
1.01배낭문제.
2.각 단계에서 물건을 하나씩 뽑는다.
각 물건을 선택한 조합을 뽑는 것은 n=100으로 불가능하기 때문에 이 방법은 안된다.
3.각 물건의 상태는 뽑거나 뽑지 않은 경우뿐이며, 
몇번째 물건을 선택할 지와 가방의 현재 무게만 안다면 이후의 문제를 쉽게 쪼갤 수 있다.
위의 경우 순번 cnt와 현재 무게 W의 조합은 모두 서로 다른 값이며 
참조적 투명성(하나의 입력에 대해 하나의 결과만 출력)을 유지한다.
4.함수 정의:
solve(cnt,W)=cnt번째 물건을 뽑아야 할 때 현재 무게가 W일 경우 
모든 물건을 뽑았을 때의 최대 가치합
점화식:
solve(cnt,W)=max(P(picked)+solve(cnt+1,W-W(picked)),solve(cnt+1,W)))
기저 사례:
W<0 => 매우 작은 음수 출력
cnt==n => 0 출력
*/