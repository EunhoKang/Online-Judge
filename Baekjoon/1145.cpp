#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n[5];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<5;++i)cin>>n[i];
    for(int i=1;i<=1000000;++i){
        int cnt=0;
        for(int j=0;j<5;++j){
            if(i%n[j]==0)cnt++;
        }
        if(cnt>2){
            cout<<i;
            break;
        }
    }
    return 0;
}