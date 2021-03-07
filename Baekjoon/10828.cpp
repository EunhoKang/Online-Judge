#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string s, char del){
    vector<string> res;
    string temp;
    stringstream ss(s);
    while(getline(ss,temp,del)){
        res.push_back(temp);
    }
    return res;
}



int main(){
    int n;
    cin>>n;
    cin.ignore();
    stack<int> S;
    vector<string> str;
    for(int i=0;i<n;++i){
        string tp;
        getline(cin,tp);
        str.push_back(tp);
    }
    for(int i=0;i<n;++i){
        string tp=str[i];
        vector<string> cmd=split(tp,' ');
        if(cmd[0]=="push") S.push(stoi(cmd[1]));
        if(cmd[0]=="pop") {
            if(!S.empty()){
                cout<<S.top()<<'\n';
                S.pop();
            }else{
                cout<<"-1\n";
            }
        }
        if(cmd[0]=="size") cout<<S.size()<<'\n';
        if(cmd[0]=="empty") cout<<(S.empty() ? 1 : 0)<<'\n';
        if(cmd[0]=="top") {
            if(!S.empty()){
                cout<<S.top()<<'\n';
            }else{
                cout<<"-1\n";
            }
        }
    }
}
