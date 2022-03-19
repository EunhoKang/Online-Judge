#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int T;
int n;
int siz[500];
int cache[500][500];
vector<int> itrace;
int cnt=0;

int dp(int x, int y){
    if(x==y)return siz[x];
    int & res=cache[x][y];
    if(res!=-1)return res;
    res=INF;
    int tp=-1;
    for(int i=x;i<y;++i){
        int temp=dp(x,i)+dp(i+1,y);
        if(res>temp){
            tp=i;
            res=temp;
        }
    }
    itrace.push_back(tp);
    return res;
}

int trace(int x, int y){
    if(x==y)return cache[x][y];
    int res=cache[x][y]+trace(x,itrace[cnt])+trace(itrace[cnt]+1,y);
    cnt++;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        memset(cache,-1,sizeof(cache));
        itrace.clear();
        cnt=0;
        for(int i=0;i<n;++i)cin>>siz[i];
        cout<<dp(0,n-1)<<'\n';
    }
    return 0;
}

/*
1.문제에 따르면 더해진 덩어리를 다시 더해야 하고, 이 과정에서 한 파일이 여러변 연산된다.
필연적으로 여러번 연산되는 파일의 크기가 최소가 되면 된다. 
즉, 모든 순간에 가장 작은 파일을 더한다.
====
연속된 파일끼리만 합쳐야 한다. 그리디를 하면 안됨.
그렇다면 브루트로 한다고 쳤을 때 500C2*499C2*...이렇게 되면 시간안에 못 풀기 때문에
DP를 할 수 있는지 확인해야 한다.
D(x,y)=>x~y번째 파일을 합치는데 필요한 최소 비용
D(x,y)=두 부분으로 쪼갰을 때 두 조각의 합 중 최소
https://cocoon1787.tistory.com/317
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