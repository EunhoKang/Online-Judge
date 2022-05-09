#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1187654321;

int T;
string wildcard;
int n;
string matches[50];
string match;
int cache[101][101];

int IsCorrect(int a, int b, int maxA, int maxB){
    if(a==maxA && b==maxB)return 1;
    if(a==maxA || b==maxB){
        if(wildcard[a]=='*' && a==maxA-1)return 1;
        return 0;
    }
    int & res=cache[a][b];
    if(res!=-1)return res;
    if(wildcard[a]==match[b] || wildcard[a]=='?')return res=IsCorrect(a+1,b+1,maxA,maxB);
    else if(wildcard[a]=='*')return res=(IsCorrect(a+1, b+1, maxA, maxB) || IsCorrect(a, b+1, maxA, maxB));
    else return res=0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>wildcard>>n;
        for(int i=0;i<n;++i)cin>>matches[i];
        vector<string> temp;
        for(int i=0;i<n;++i){
            memset(cache, -1, sizeof(cache));
            match=matches[i];
            if(IsCorrect(0,0,wildcard.length(),match.length()))temp.push_back(matches[i]);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();++i)cout<<temp[i]<<'\n';
    }
    return 0;
}

/*
1. 문자열이 최대 100까지 길어질 수 있어 브루트포스는 힘들어보인다.
2. 문자열 비교에서 *을 만나면 선택지는 둘이다.
1) *이 끝났다고 인식하고 다음으로 넘어가거나, 2) *이 아직 안 끝났다고 인식하고 계속 *을 유지하거나
이 과정은 모든 문자로 하여금 경우의 수를 나누게 한다. 이 때 1씩 각 문자열이 증감하므로 반드시 겹치는 사례가 발생한다.
3. IsCorrect(a,b) => 와일드 카드 a, 원본 b의 문자를 비교하고 있을 때, 해당 문자열이 일치하는지 구하라.
IsCorrect(a,b) = IsCorrent(a+1, b+1) && IsCorrent(a, b+1)
기저 사례 : 둘다 마지막이면 true 반환
둘이 동시에 끝나지 못했거나 경우가 이어지지 못하면 false 반환
/*
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