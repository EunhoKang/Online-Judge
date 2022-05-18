#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

string str;

vector<int> split(string st, char del);

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>str;
    vector<int> num;
    vector<int> ismin;
    string s;
    stringstream ss(str);
    while(getline(ss,s,'+')){
        stringstream sss(s);
        string temp;
        while(getline(sss,temp,'-')){
            num.push_back(stoi(temp));
        }
    }
    for(char i : str){
        if(i=='+')ismin.push_back(0);
        else if(i=='-')ismin.push_back(1);
    }
    int res=num[0];
    int flag=0;
    for(int i=0;i<ismin.size();++i){
        if(ismin[i]==1){
            flag=1;
        }
        if(flag==1)res-=num[i+1];
        else res+=num[i+1];
    }
    cout<<res<<'\n';
    return 0;
}

/*
1. 뺄셈이 있을 경우 다음 뺄셈이 나오기 전까지 전부 합쳐서 빼면 최소가 된다.
즉 뺄셈 뒤의 모든 수는 빼버리면 된다.
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