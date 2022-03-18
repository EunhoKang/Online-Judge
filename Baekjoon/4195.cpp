#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

struct NaiveDisjointSet { 
    vector<int> parent;
    vector<int> siz;
    map<string,int> mp;
    int cnt=0;

    int insert(string s){
        if(mp.find(s)==mp.end()){
            mp.insert({s,cnt});
            parent.push_back(cnt);
            siz.push_back(1);
            return cnt++;
        }else{
            return mp[s];
        }
    }
    int find (int u) { 
        if (u == parent[u]) return u;  
        int res=find(parent[u]);
        siz[u]=siz[res];
        return parent[u]=res; 
    } 
    int merge (int u, int v){
        u = find(u); v = find(v); 
        if (u == v) return siz[u]; 
        siz[v]+=siz[u];
        parent[u] = v; 
        return siz[v];
    } 
};

int T;
int n;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        NaiveDisjointSet set;
        int cnt=0;
        for(int i=0;i<n;++i){
            string a,b;
            cin>>a>>b;
            cout<<set.merge(set.insert(a),set.insert(b))<<'\n';
        }
    }
    return 0;
}

/*
유니온파인드의 합을 구하는 함수를 만든다.
*/