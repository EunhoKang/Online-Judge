#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int e,m;
double len;
double graph[1001][1001];
pair<int,int> pos[1001];
double shortest[1001];

double GetDistance(int a,int b){
    double res=pow(pos[a].first-pos[b].first,2)+pow(pos[a].second-pos[b].second,2);
    return pow(res,0.5);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>e>>m>>len;
    for(int i=1;i<=e;++i)for(int j=1;j<=e;++j)graph[i][j]=INF;
    for(int i=1;i<=e;++i)graph[i][i]=0;
    for(int i=1;i<=e;++i){
        int a,b;cin>>a>>b;
        pos[i]=make_pair(a,b);
        for(int j=1;j<i;++j){
            double dis=GetDistance(i,j);
            graph[i][j]=dis;
            graph[j][i]=dis;
        }
    }
    for(int i=0;i<m;++i){
        int a,b;cin>>a>>b;
        graph[a][b]=0;
        graph[b][a]=0;
    }
    for(int i=2;i<=e;++i)shortest[i]=INF;
    priority_queue<pair<float,int>> pq;
    pq.push(make_pair(-shortest[1],1));
    while(!pq.empty()){
        pair<double,int> pr=pq.top();pq.pop();
        if(pr.first+shortest[pr.second]>0.0001)continue;
        for(int i=1;i<=e;++i){
            if(graph[pr.second][i]<len){
                if(shortest[i]>shortest[pr.second]+graph[pr.second][i]){
                    shortest[i]=shortest[pr.second]+graph[pr.second][i];
                    pq.push(make_pair(-shortest[i],i));
                }
            }
        }
    }
    cout<<(int)(shortest[e]*1000);
    return 0;
}

/*
1.이미 이어진 상태의 발전소는 최단거리가 0이다. 더 전선을 깔 필요가 없기 때문.
즉 구하는 최단거리는 추가로 설치하는 전선의 길이만을 의미한다.
----
2.다익스트라는 맨 처음 초기화 시 전부 무한대를 넣어야 한다.
그래야 정상적인 초기화가 가능하다.
3.실수 사용시 등호 처리에 신경써야 한다. 아주 작은 오차 때문에 등호가 성립되지 않을 수 있다.
*/