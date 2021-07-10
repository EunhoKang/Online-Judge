#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int v;
int graph[21][21];
int useless[21][21];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>v;
    for(int i=1;i<=v;++i)for(int j=1;j<=v;++j)graph[i][j]=INF;
    for(int i=1;i<=v;++i)graph[i][i]=0;
    for(int i=1;i<=v;++i)for(int j=1;j<=v;++j)cin>>graph[i][j];
    for(int k=1;k<=v;++k)
        for(int i=1;i<=v;++i)
            for(int j=1;j<=v;++j){
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                    cout<<-1;
                    return 0;
                }
                if(i<j && i!=k && k!=j){
                    if(graph[i][j]==graph[i][k]+graph[k][j]){
                        useless[i][j]=1;
                    }
                }
            }
    int sum=0;
    for(int i=1;i<=v;++i){
        for(int j=i+1;j<=v;++j){
            if(useless[i][j]!=1)sum+=graph[i][j];
        }
    }
    cout<<sum;
    return 0;
}
/*
1.도로가 굳이 필요없다는 뜻은 
굳이 최단거리가 나오는 경우의 수가 여러개일 필요가 없다는 것.
만약 1-3과 1-2 + 2-3의 가중치합이 같다면, 1-3은 필요 없는 도로.
2.플로이드 와샬은 모든 간선을 비교해보므로 이 알고리즘을 활용한다.
---
이미 최단거리로 만들어진 표이므로 
만약 구하는 중에 더 작은 최단거리가 하나라도 나온다면,
이는 입력된 표가 잘못된 것이므로 도로의 수를 구하는 게 불가능함을 뜻한다.
*/