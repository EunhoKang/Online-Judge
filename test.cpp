#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
pair<int,int> flower[100000];

int cache[100000][13][32];

int water(int idx, int month, int day){
    if(idx==n){
        if(month*100+day>1130)return 0;
        else return INF;
    }
    int & res=cache[idx][month][day];
    if(res!=-1)return res;
    if(month*100+day>=flower[idx].first){
        res=min(1+water(idx+1,flower[idx].second/100,flower[idx].second%100),water(idx+1,month,day));
    }else{
        res=water(idx+1,month,day);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        flower[i]={a*100+b,c*100+d};
    };
    sort(flower,flower+n);
    memset(cache,-1,sizeof(cache));
    if(water(0,3,1)>=INF)cout<<0;
    else cout<<water(0,3,1);
    return 0;
}

/*
1. 
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