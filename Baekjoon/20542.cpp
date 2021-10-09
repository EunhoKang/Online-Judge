#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n,m;
string A,B;
vector<vector<int>> cache; 

int EditDistance(int i, int j){
    int & res=cache[i][j];
    if(cache[i][j]!=-1)return res;
    res=INF;
    if(A[i-1]!=B[j-1]){
        if(A[i-1]=='i'){
            if(B[j-1]=='l' || B[j-1]=='j'){
                res=EditDistance(i-1,j-1);
            }else{
                res=min(EditDistance(i-1,j-1),min(EditDistance(i,j-1),EditDistance(i-1,j)))+1;
            }
        }else if(A[i-1]=='v' && B[j-1]=='w'){
            res=EditDistance(i-1,j-1);
        }else{
            res=1+min(EditDistance(i-1,j-1),min(EditDistance(i,j-1),EditDistance(i-1,j)));
        }
    }else{
        res=EditDistance(i-1,j-1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>A>>B;
    for(int i=0;i<=n;++i){
        cache.push_back({});
        for(int j=0;j<=m;++j){
            cache[i].push_back(-1);
        }
    }
    for(int i=0;i<=n;++i)cache[i][0]=i;
    for(int i=0;i<=m;++i)cache[0][i]=i;
    cout<<EditDistance(n,m)<<'\n';
    return 0;
}

/*
n*m=1억이므로 vector로 dp를 해야 한다.
최소 편집거리 알고리즘을 활용한다.
*/