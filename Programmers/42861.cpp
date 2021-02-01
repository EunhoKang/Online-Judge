#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int,pair<int,int>>> T;
    for(int i=0;i<costs.size();++i){
        pair<int,pair<int,int>> tp=make_pair(costs[i][2],make_pair(costs[i][0],costs[i][1]));
        T.push_back(tp);
    }
    sort(T.begin(),T.end());
    int selected=0;
    int idx=0;
    NaiveDisjointSet Set(n);
    while(selected<n-1){
        pair<int,pair<int,int>> tp=T[idx];
        if(Set.merge(tp.second.first,tp.second.second)){
            answer+=tp.first;
            selected++;
        }
        idx++;
    }
    return answer;
}

/*
1.https://eehoeskrap.tistory.com/39
2.https://chanhuiseok.github.io/posts/algo-33/
3.https://dheldh77.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%9C%A0%EB%8B%88%EC%98%A8%ED%8C%8C%EC%9D%B8%EB%93%9CUnion-Find-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-1
*/