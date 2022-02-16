#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
ll cache[91];

ll fibo(int idx){
    if(idx==0)return 0;
    if(idx==1)return 1;
    ll & res=cache[idx];
    if(res!=-1)return res;
    return res=fibo(idx-1)+fibo(idx-2);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fill(cache,cache+91,-1);
    cin>>n;
    cout<<fibo(n);
    return 0;
}