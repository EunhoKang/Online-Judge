#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

map<string,int> dictionary;
int n;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string tree;
    while(getline(cin,tree)){
        if(dictionary.find(tree)==dictionary.end()){
            dictionary[tree]=1;
        }else dictionary[tree]++;
        n++;
    }
    //sort(dictionary.begin(),dictionary.end());
    cout<<fixed;
    cout.precision(4);
    map<string,int>::iterator it;
    for(it=dictionary.begin();it!=dictionary.end();it++){
        double percent=it->second;
        cout<<it->first<<" "<<percent/n*100<<'\n';
    }
    return 0;
}

/*
1.끝날때까지 입력하는 경우 eof나 getline을 직접 넣는다.
2.map은 자동정렬된 상태.
*/