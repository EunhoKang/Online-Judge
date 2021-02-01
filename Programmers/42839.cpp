#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> decimals;

int isDecimal(string s){
    int num;
    stringstream ssInt(s);
    ssInt>>num;
    if(num==1) return 0;
    for(int i=0;i<decimals.size();++i){
        if(decimals[i]==num) return 0;
    }
    for(int i=2;i<3500;++i){
        if(num%i==0 &&num!=i) return 0;
    }
    decimals.push_back(num);
    return 1;
}

int FindDecimal(string s,string back,vector<int> pick){
    if(back.size()==s.size() ) return 0;
    int res=0;
    for(int i=0;i<s.size();++i){
        if(pick[i]==0){
            pick[i]=1;
            res+=isDecimal(back+s[i])+FindDecimal(s,back+s[i],pick);
            pick[i]=0;
        }
    }
    return res;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> pick;
    for(int i=0;i<numbers.size();++i) pick.push_back(0);
    answer=FindDecimal(numbers,"",pick);
    return answer;
}

int main(){
    int s=solution("011");
    cout<<s;
}