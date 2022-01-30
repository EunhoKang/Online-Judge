#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int cache[21];

int pibo(int n){
    int & res=cache[n];
    if(res!=-1)return res;
    if(n==0)return 0;
    if(n==1)return 1;
    return pibo(n-1)+pibo(n-2);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fill(cache,cache+21,-1);
    int x;
    cin>>x;
    cout<<pibo(x);
    return 0;
}