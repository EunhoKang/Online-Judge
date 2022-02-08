#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
string str[50];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str[i];
    } 
    string res=str[0];
    for(int i=1;i<n;++i){
        for(int j=0;j<res.length();++j){
            if(res[j]!=str[i][j])res[j]='?';
        }
    }
    cout<<res;
    return 0;
}