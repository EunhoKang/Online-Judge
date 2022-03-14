#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

string a,b;
int cache[1001][1001];

int dp(int n,int m){
    if(n>a.length())return 0;
    int & res=cache[n+1][m+1];
    if(res!=-1) return res;
    res=0;
    for(int i=m+1;i<=b.length();++i){
        if(a[n]==b[i]){
            for(int j=n+1;j<=a.length();++j){
                res=max(1+dp(j,i),res);
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>a>>b;
    cout<<dp(0,-1);
    return 0;
}

/*
1.위쪽 것을 기준으로 구한다.
어떤 원소를 선택하게 될 경우, 반대편에서 해당 원소와 같은 원소를 찾는다.
만약 하나라도 겹치는 원소가 있다면, 이후의 원소에 대해 이러한 행위를 반복한다.
이를 통해 위쪽 문자열의 순회가 끝났거나 더이상 겹치는 것을 찾을 수 없다면 길이를 반환한다.
이 과정에서 어떤 원소를 선택하던 그 선택이 이후의 값에 영향을 주지 않으므로,
부분의 최적해가 곧 전체의 최적해가 된다.(최적 부분 구조 성립)
따라서 동적 계획법을 쓰기 적절한 구조이므로 위쪽 문자열의 인덱스를 기준으로 캐싱을 진행한다.
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