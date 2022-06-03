#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=21000000;

struct NaiveDisjointSet{
    int parent[1001];
    NaiveDisjointSet(int n){
        for (int i=1; i <= n; i++) parent[i]=i; 
    }
    int find(int u){
        if(parent[u]==u)return u;
        return parent[u]=find(parent[u]);
    }
    bool merge(int u, int v){
        u=find(u);
        v=find(v);
        if(u==v)return false;
        parent[u]=v;
        return true;
    }
};

int n,m;
double x[1001],y[1001];

int main() {
    
    cin>>n>>m;
    NaiveDisjointSet uf=NaiveDisjointSet(n);
    for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
    for(int i=1;i<=m;++i){
        int a,b;
        cin>>a>>b;
        uf.merge(a,b);
    }
    vector<pair<double,pair<int,int>>> list;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(i==j)continue;
            double vertex=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            list.push_back({vertex,{i,j}});
        }
    }
    sort(list.begin(),list.end());
    double res=0;
    for(auto node : list){
        if(uf.merge(node.second.first,node.second.second)){
            res+=node.first;
        }
    }
    res=round(res*100);
    printf("%.2f",res/100);
    return 0;
}