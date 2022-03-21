#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=INT_MAX;

int n;
ll building[80000];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>building[i];
    }
    stack<int> st;
    ll res=0;
    for(int i=0;i<n;++i){
        while(!st.empty() && st.top()<=building[i]){
            st.pop();
        }
        res+=st.size();
        st.push(building[i]);
    }
    cout<<res;
    return 0;
}

/*
1.일반적으로 일방통행에 불연속 값을 쓰는 경우 스택을 고려해볼 수 있다.
1-1.관리인이 보는 옥상의 갯수가 아니라 보여지는 옥상의 수를 센다고 생각해보자.
어차피 왼쪽에서 오른쪽으로 계속 건물이 추가된다고 했을 때 이 옥상이 몇명에게 보여지느냐를 계산해도 값은 똑같다.
1-2.만약 더 높은 건물이 들어서면 최고 높이와 위치를 갱신한다. 이후 가장 높은 건물과 추가된 건물 사이의 작은 값을 전부 제거한다.
더 낮은 건물이 들어올 경우, 보여지는 건물의 수를 센다.
//
수도 없이 틀리고 나서야 자료형에 문제가 있음을 알았다.
이거 근데 왜 같은 높이 빌딩에 대해서는 언급이 없는지 모르겠다. 일단 같은 높이면 못본다.
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