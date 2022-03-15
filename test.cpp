#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int T;
int n;
char S[64];
ll cache[64][10];

ll dp(int cnt,int k){
    if(cnt>=n)return 1;
    ll & res=cache[cnt][k];
    if(res!=-1)return res;
    res=0;
    for(int i=0;i<10;++i){
        if(k<=i){
            res+=dp(cnt+1,i);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>T;
    while(T--){
        memset(cache,-1,sizeof(cache));
        cin>>n;
        cout<<dp(0,0)<<'\n';
    }
    return 0;
}

/*
1.어떤 숫자를 만들 때, 
앞에서의 증가가 보장된다면 어떤 자리에서의 숫자에 대해 이후부터의 갯수는 항상 같다.
D(n,k) => n번째 자리 결정 시 n-1번째 자리의 수가 k일 경우 앞으로 만들 수 있는 줄어들지 않는 수의 개수
D(n,k)=D(n+1,k')+~+D(n+1,9) (k'>=k)
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