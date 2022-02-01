#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int cnt=0;
string lines[500];

string reverseLine(string original){
    string temp="";
    for(int i=0;i<original.length();++i){
        temp+=original[original.length()-1-i];
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(true){
        string temp;
        getline(cin,temp);
        if(temp=="END")break;
        lines[cnt]=reverseLine(temp);
        cnt++;
    }
    for(int i=0;i<cnt;++i){
        cout<<lines[i]<<'\n';
    }
    return 0;
}