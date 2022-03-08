#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int N,m;
static char nums[10]={'0','1','2','3','4','5','6','7','8','9'};
bool broken[10]={false,};
int res=INF;
string remoteNum="";

void brute(int n,int targetN){
    if(remoteNum.length()>0){
        res=min(abs(stoi(remoteNum)-N)+n,res);
    }
    if(n>=targetN){
        return;
    }else{
        string temp=remoteNum;
        for(int i=0;i<10;++i){
            if(broken[i])continue;
            remoteNum+=nums[i];
            brute(n+1,targetN);
            remoteNum=temp;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>m;
    for(int i=0;i<m;++i){
        int k;
        cin>>k;
        broken[k]=true;
    }
    int cnt=to_string(N).size();
    if(N==100)cout<<0;
    else{
        brute(0,7);
        cout<<min(res,abs(N-100));
    }
    return 0;
}

/*
15684
1038
17406
*/

/*
vector<string> split(string str,char del){
    vector<string> res;
    string s;
    stringstream ss(str);
    while(getline(ss,s,del)){
        res.push_back(s);
    }
    return res;
}
*/