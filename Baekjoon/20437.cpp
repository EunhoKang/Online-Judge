#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;
string W;
int K;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    for(int I=0;I<T;++I){
        cin>>W;
        cin>>K;
        vector<int> dic[26];
        int minstrlen=987654321;
        int maxstrlen=0;
        for(int i=0;i<W.length();++i)dic[W[i]-'a'].push_back(i);
        for(int i=0;i<26;++i){
            if(dic[i].size()>=K){
                for(int j=0;j<dic[i].size()-K+1;++j){
                    minstrlen=min(minstrlen,dic[i][j+K-1]-dic[i][j]+1);
                    maxstrlen=max(maxstrlen,dic[i][j+K-1]-dic[i][j]+1);
                }
            }
        }
        if(maxstrlen==0)cout<<-1<<'\n';
        else cout<<minstrlen<<" "<<maxstrlen<<'\n';
    }
    return 0;
}
/*
1.각 문자마다 n번째 단어가 언제 등장하는지 확인한다.
소문자 수가 26개여서 직접 다 세면 된다.
*/