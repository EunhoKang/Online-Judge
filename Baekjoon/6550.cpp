#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

string s,t;

void comb(){
    int idx=0;
    for(int i=0;i<=t.length();++i){
        if(t[i]==s[idx]){
            idx++;
            if(idx>=s.length())break;
        }
    }
    if(idx>=s.length())cout<<"Yes\n";
    else cout<<"No\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while (cin>>s>>t){
        comb();
    }
    return 0;
}