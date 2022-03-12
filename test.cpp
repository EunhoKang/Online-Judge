#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

struct NaiveDisjointSet { 
    vector<int> parent; 
    NaiveDisjointSet(int n): parent(n) { 
        for (int i=0; i < n; i++) parent[i]=i; 
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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //
    return 0;
}

/*
1.x,y,z,여기에 시간까지 포함된 노드 탐색
2.좌표 방향을 잘 잡아줘야 한다.
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