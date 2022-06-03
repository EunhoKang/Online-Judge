#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=21000000;

int n, m, v1, v2, X[1002], Y[1002];

double sqr(double d){return d*d;}

struct NaiveDisjointSet{
    int parent[1002];
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

int main(){
    double ans = 0;
    cin>>n>>m;
    NaiveDisjointSet uf=NaiveDisjointSet(n);
    for(int i = 1; i <= n; i++){
        cin>>X[i]>>Y[i];
    }
    for(int i = 0; i < m; i++){
        cin>>v1>>v2;
        uf.merge(v1, v2);
    }
    priority_queue<pair<double,pair<int,int>>> pq;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            double d = sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]);
            pq.push({-d, {i, j}});
        }
    }
    int cnt = m;
    while(!pq.empty() && cnt != n - 1){
        auto top = pq.top(); pq.pop();
        double tv = top.first;
        int tx = top.second.first, ty = top.second.second;
        if(uf.merge(tx, ty))ans += sqrt(-tv), cnt++;
    }
    printf("%.2f", ans);
}

/*
1.특정 위치에서 이전의 선택은 이후의 결과에 영향x -> DP

*/
























/*
vector<string> split(string str,char del){
    vector<string> res;
    string s;
    stringstream ss(str);
    while(getline(ss,s,del)){
        res.push_back(s);
    }
    return res;
}
struct NaiveDisjointSet { 
    vector<int> parent; 
    NaiveDisjointSet(int n): parent(n) { 
        for (int i=0; i <= n; i++) parent[i]=i; 
    } 
    int find (int u) { 
        if (u == parent[u]) return u;  
        return parent[u]=find(parent[u]); 
    } 
    bool merge (int u, int v){
        u = find(u); v = find(v); 
        if (u == v) return false; 
        parent[u] = v; 
        return true;
    } 
};
*/