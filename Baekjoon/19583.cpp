#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string s, char del){
    vector<string> res;
    stringstream ss(s);
    string tp;
    while(getline(ss,tp,del)){
        res.push_back(tp);
    }
    return res;
}

int main(){
    string T[3];
    cin>>T[0]>>T[1]>>T[2];
    cin.ignore();
    int res=0;
    map<string,int> M;
    while(true){
        string time,name,temp;
        getline(cin,temp);
        if(temp=="") break;
        vector<string> S=split(temp,' ');
        time=S[0];name=S[1];
        if("00:00"<=time && time<=T[0]){
            if(M.find(name)==M.end()){
                M.insert({name,1});
            }
        }else if(T[1]<=time && time<=T[2]){
            if(M.find(name)!=M.end() && M[name]==1){
                M[name]++;
                res++;
            }
        }
    }
    cout<<res;
}

/*
받는 갯수 제한이 없는 문제...?
엔터 두번 누르면 넘어가게 했다.
*/