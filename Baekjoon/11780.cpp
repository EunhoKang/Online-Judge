#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n,m;
int graph[100][100];
int before[100][100];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)fill(graph[i],graph[i]+100,INF);
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a-1][b-1]=min(graph[a-1][b-1],c);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            before[i][j]=i;
        }
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j)continue;
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                    before[i][j]=before[k][j];
                }
            } 
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(graph[i][j]>=INF)cout<<0<<" ";
            else cout<<graph[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(graph[i][j]>=INF)cout<<0<<"\n";
            else{
                int k=j;
                int cnt=0;
                stack<int> shortest;
                shortest.push(j);
                while(k!=i){
                    k=before[i][k];
                    shortest.push(k);
                    cnt++;
                }
                cout<<cnt+1<<" ";
                while(!shortest.empty()){
                    cout<<shortest.top()+1<<" ";
                    shortest.pop();
                }
                cout<<'\n';
            }
        }
    }
    return 0;
}