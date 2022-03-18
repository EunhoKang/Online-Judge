#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n,m;
int dest[100001];
int railcnt[100001];
int ticket[100001];
int IC[100001];
int card[100001];

int segtree[1000][100000];

int settree(int s, int e){
    //
    return 0;
}

void gettree(int s, int e){
    //
}

void lazyupdate(){
    //
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;++i)cin>>dest[i];
    for(int i=1;i<n;++i)cin>>ticket[i]>>IC[i]>>card[i];
    for(int i=1;i<m;++i){
        for(int j=min(dest[i-1],dest[i]);j<max(dest[i-1],dest[i]);++j){
            railcnt[j]++;
        }
    }
    int res=0;
    for(int i=1;i<n;++i){
        res+=min(ticket[i]*railcnt[i],IC[i]*railcnt[i]+card[i]);
    }
    cout<<res;
    return 0;
}

/*
https://www.acmicpc.net/problem/10713
1.선택 가능한 요소는 IC 카드의 구매 유무뿐이다.
경로가 설정되는 순간 특정 구간을 몇번 경우하는지는 정해지므로,
여기에 곱할 변수만 생각해두면 된다.
2.각각의 철도에서 계산되는 값은 다른 첼도의 계산에 영향을 주지 않는다.
따라서 티켓과 IC카드 사용시 얻는 해당 철도에 지불하는 총 금액만 비교해 낮은 값들을 전부 더한다.
------
1->N->1->N과 같은 식이면 O(NM)으로 시간 초과가 발생한다.
세그먼트 트리를 이용해 최대 최소값의 임계점이 넘어갈 때마다 값을 업데이트해주는 방식을 사용한다.
이때 업데이트를 바로 하면 계산 횟수가 늘어날 수 있으므로 lazy propagation을 사용한다.
https://yabmoons.tistory.com/431
https://yabmoons.tistory.com/442

https://www.acmicpc.net/problem/4195
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