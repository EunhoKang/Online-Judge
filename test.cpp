#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int T;
int n;
int siz[500];
int cache;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int cnt=0;
        for(int i=0;i<n;++i){
            string a,b;
            cin>>a>>b;
        }
    }
    return 0;
}

/*
1.문제에 따르면 더해진 덩어리를 다시 더해야 하고, 이 과정에서 한 파일이 여러변 연산된다.
필연적으로 여러번 연산되는 파일의 크기가 최소가 되면 된다. 
즉, 모든 순간에 가장 작은 파일을 더한다.
https://www.acmicpc.net/problem/11066
https://www.acmicpc.net/problem/1987
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