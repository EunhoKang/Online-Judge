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

int n,m;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    NaiveDisjointSet* naive=new NaiveDisjointSet(n);//유니온파인드 선언
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        if(naive->find(a)==naive->find(b)){//만약 두 점이 같은 집합이라면
            cout<<i+1<<'\n';// i+1번째에 사이클 발생
            return 0;
        }
        naive->merge(a,b);//사이클이 없다면 합집합 연산 진행
    }
    cout<<0<<'\n';
    return 0;
}
/*
1.모든 세 점이 직선 위에 없다,이미 선택된 선분은 선택되지 않는다 
-> 사이클 발생하려면 이미 방문한 적 있는 점 두개가 선택되어야 한다.
2.이미 방문한 점 두개가 선택되어도 사이클이 발생하지 않을 수 있다.
->서로가 같은 집합안에 있으면 사이클 발생
->유니온파인드 사용
3.사이클은 두 점의 선분이 이어질 때, 그 두 점이 포함된 집합 안에서만 검사하면 된다.
*/