#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> split(string s, char del){
    vector<int> res;
    stringstream ss(s);
    string tp;
    while(getline(ss,tp,del)){
        res.push_back(stoi(tp));
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> cafe;
    cafe.push_back({-1,0});
    cin.ignore();
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        cafe.push_back({x,y});
    }
    sort(cafe.begin(),cafe.end());
    vector<int> xp;
    for(int i=1;i<cafe.size();++i){
        if(cafe[i-1][0]!=cafe[i][0]) {
            xp.push_back(i);
        }
    }

    for(int i=0;i<xp.size();++i){
        if(cafe[xp[i]][1]!=cafe[xp[i]-1][1]){
            if(i==xp.size()-1) sort(cafe.begin()+xp[i],cafe.end(),greater<>());
            else sort(cafe.begin()+xp[i],cafe.begin()+xp[i+1],greater<>());
        }
    }
    
    string temp;
    cin.ignore();
    getline(cin,temp);
    vector<int> num=split(temp,' ');
    for(int i=1;i<num.size();++i){
        cout<<cafe[num[i]][0]<<" "<<cafe[num[i]][1]<<'\n';
    }
}

int main(){
    int N;
    cin>>N;
    cin.ignore();
    for(int k=0;k<N;++k){
        solve();
    }
}

/*
처음에 제대로 구상하는게 중요하다. 앞에서부터 맞춰나가야한다.
*/