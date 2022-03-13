#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

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
vector<int> parent; 

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

int n,m;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=0; i <= n; i++) parent.push_back(i); 
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){//0이면 두 집합을 합침
            merge(b,c);
        }else{//1이면 두 원소의 부모가 같은지 확인.
            cout<<((find(b)==find(c)) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}

/*
1.유니온파인드 자료구조를 사용한다.
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
*/