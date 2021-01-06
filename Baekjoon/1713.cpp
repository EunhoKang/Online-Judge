#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>
using namespace std;

int n,s;
vector<int> vote;
vector<pair<int,int>> port;

int find_stud(int n){
    for(int i=0;i<port.size();++i){
        if(port[i].first==n) return i;
    }
    return -1;
}

int find_stud_least(){
    int res=987654321;
    int pos=-1;
    for(int i=0;i<port.size();++i){
        if(port[i].second<res){
            pos=i;
            res=(port[i].second);
        }
    }
    return pos;
}

void Solve(int n, int k){
    for(int i=0;i<vote.size();++i){
        int temp=find_stud(vote[i]);
        if(temp==-1){
            if(port.size()<n){
                port.push_back(make_pair(vote[i],1));
            }else{
                port.erase(port.begin()+find_stud_least());
                port.push_back(make_pair(vote[i],1));
            }
        }else{
            port[temp].second++;
        }
    }
    sort(port.begin(),port.end());
    for(int i=0;i<n;++i){
        cout<<port[i].first<<" ";
    }
}

vector<int> split(string s,char del){
    vector<int> res;
    string tp;
    stringstream ss(s);
    while(getline(ss,tp,del)){
        res.push_back(stoi(tp));
    }
    return res;
}

int main(){
    cin>>n;
    cin>>s;
    cin.ignore();
    string tp;
    getline(cin,tp);
    vote=split(tp,' ');
    Solve(n,s);
}

/*
1.만약 갯수가 겹칠 겨우 가장 오래된 사진을 삭제해야 한다.
->뒤에서부터 넣는 자료구조에서 가장 앞에 있는 걸 기억하면 된다.
즉 앞에서부터 세면서 가장 작은 최초값만 기억하면 된다. 이건 부등호로도 할 수 있다.
가장 최근에 추가된 게 뒤에 있기 때문이다.
2.어차피 번호순으로 뽑으니 정렬 상태는 상관이 없다. 마지막에만 한다.
*/