#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

string keys[8]={"c=","c-","dz=","d-","lj","nj","s=","z="};
string replaces[8]={"c","c","d","d","l","n","s","z"};
string str;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>str;
    for(int i=0;i<8;++i){
        str=regex_replace(str,regex(keys[i]),replaces[i]);
    }
    cout<<str.length();
    return 0;
}