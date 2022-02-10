#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n,m;
int problemnum[100000];
int problemlevel[100000];

vector<string> split(string str,char del){
    vector<string> res;
    string s;
    stringstream ss(str);
    while(getline(ss,s,del)){
        res.push_back(s);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    priority_queue<pair<int,int>> pq_big;
    priority_queue<pair<int,int>> pq_small;
    priority_queue<pair<int,int>> pq_bigpop;
    priority_queue<pair<int,int>> pq_smallpop;
    map<int,int> dic;
    for(int i=0;i<n;++i){
        cin>>problemnum[i]>>problemlevel[i];
        pq_big.push({problemlevel[i],problemnum[i]});
        pq_small.push({-problemlevel[i],-problemnum[i]});
        dic[problemnum[i]]=problemlevel[i];
    }
    cin>>m;
    cin.ignore();
    for(int i=0;i<m;++i){
        string commandline;
        getline(cin,commandline);
        vector<string> temp=split(commandline,' ');
        if(temp[0]=="recommend"){
            if(temp[1]=="1"){
                pair<int,int> target=pq_big.top();
                while(!pq_bigpop.empty() && target==pq_bigpop.top()){
                    pq_bigpop.pop();
                    pq_big.pop();
                    target=pq_big.top();
                }
                cout<<target.second<<'\n';
                pq_big.pop();
                pq_smallpop.push({-target.first,-target.second});
            }else{
                pair<int,int> target=pq_small.top();
                while(!pq_smallpop.empty() && target==pq_smallpop.top()){
                    pq_smallpop.pop();
                    pq_small.pop();
                    target=pq_small.top();
                }
                cout<<-target.second<<'\n';
                pq_small.pop();
                pq_bigpop.push({-target.first,-target.second});
            }
        }else if(temp[0]=="add"){
            pq_big.push({stoi(temp[2]),stoi(temp[1])});
            pq_small.push({-stoi(temp[2]),-stoi(temp[1])});
        }else if(temp[0]=="solved"){
            pq_bigpop.push({dic[stoi(temp[1])],stoi(temp[1])});
            pq_smallpop.push({-dic[stoi(temp[1])],-stoi(temp[1])});
        }
    }
    return 0;
}
/*
1. 제거된 문제가 다시 등장하는 경우를 생각해야 한다.
*/