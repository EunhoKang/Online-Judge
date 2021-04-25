#include <bits/stdc++.h>
using namespace std;

int n,m;
int G[101][101];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)G[i][j]=987654321;
    for(int i=1;i<=n;++i)G[i][i]=0;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        G[a][b]=G[b][a]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                if(G[j][k]>G[j][i]+G[i][k]){
                    G[j][k]=G[j][i]+G[i][k];
                }
            }
        }
    }
    int a,b;
    int res=987654321;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int sum=0;
            for(int k=1;k<=n;++k)sum+=min(G[i][k]+G[k][i],G[j][k]+G[k][j]);
            if(sum<res){
                a=i;b=j;res=sum;
            }
        }
    }
    cout<<a<<" "<<b<<" "<<res;
    return 0;
}
/*
1.고작 해야 100개 중 2개 뽑는 방식이므로 치킨집 두 개를 정하는 방식은 전부 해보면 된다. 두 점에서 다른 점까지의 최소값을 구하는 방식이다.
다익스트라로 두번 계산해서 최소값을 구하는 방법도 있으나,
플로이드 와샬을 써서 모든 최단거리를 미리 계산한 후 이후 연산을 편하게 할 수도 있다.
시간복잡도는 플로이드 와샬이 지배하므로 O(V^3), 1억을 넘어가지 않는다.
2.플로이드 와샬을 쓸 때는 인접 리스트 방식보다는 인접 행렬 방식이 간단하므로 그에 맞게 그래프를 만든다.
3.원래 조합을 구하는 경우 재귀로 짜면 확장성이 좋지만 어차피 두개 뽑는 문제이므로 이중포문으로 구현했다.
4.memset문은 0 혹은 -1로 초기화할때만 사용해야 한다.
5.플로이드 와샬 알고리즘 짤 때 3중 포문 순서 : 중간값->출발점->도착점
*/