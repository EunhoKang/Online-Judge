#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int n,m;
vector<pair<int,int>> edge[1001];
int a,b;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int t1,t2,t3;cin>>t1>>t2>>t3;
        edge[t1].push_back({t2,t3});
    }
    cin>>a>>b;
    int dist[1001];
    int prev[1001];
    fill(dist,dist+1001,INF);
    fill(prev,prev+1001,0);
    dist[a]=0;
    prev[a]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({-dist[a],a});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(cost>dist[cur])continue;
        for(auto next : edge[cur]){
            int nCur=next.first;
            int nCost=next.second;
            if(cost+nCost<dist[nCur]){
                prev[nCur]=cur;
                dist[nCur]=cost+nCost;
                pq.push({-dist[nCur],nCur});
            }
        }
    }
    cout<<dist[b]<<'\n';
    stack<int> st;
    st.push(b);
    int target=prev[b];
    int sum=1;
    while(target!=0){
        st.push(target);
        sum++;
        target=prev[target];
    }
    cout<<sum<<'\n';
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}