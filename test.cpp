#include <bits/stdc++.h>
#define ll long long
using namespace std;
//int INF=2100000000;
int INF=1000000000;

int n,m;
int single[2][1000];
int cache[1000][1000];

int dp(int i, int j){
    if(n>=m){if(j==m)return 0;}
    else {if(i==n)return 0;}
    int & res=cache[i][j]; 
    if(res!=-1)return res;
    res=INF;
    if(n>=m){
        for(int next=i;next<n;++next){
            res=min(res,dp(next+1,j+1)+abs(single[0][next]-single[1][j]));
        }
    }else{
        for(int next=j;next<m;++next){
            res=min(res,dp(i+1,next+1)+abs(single[1][next]-single[0][i]));
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>single[0][i];
    for(int i=0;i<m;++i)cin>>single[1][i];
    sort(single[0],single[0]+n);
    sort(single[1],single[1]+m);
    memset(cache,-1,sizeof(cache));
    cout<<(dp(0,0));
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