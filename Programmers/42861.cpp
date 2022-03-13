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
    sort(T.begin(),T.end());//오름차순의 간선 배열 생성
    int selected=0;
    int idx=0;
    NaiveDisjointSet Set(n);
    while(selected<n-1){//배열을 순회하면서 연산 진행
        pair<int,pair<int,int>> tp=T[idx];
        if(Set.merge(tp.second.first,tp.second.second)){//만약 두 집합이 집합에 속해있지 않다면
            answer+=tp.first;//해당 간선의 가중치를 더하고
            selected++;//인덱스 증가
        }
        idx++;
    }
    return answer;
}

/*
크루스칼 알고리즘을 사용하는 문제이다.
*/