#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,h;
vector<vector<int>> blocks;
int cache[50][1001];

vector<int> split(string str, char del){
    vector<int> res;
    string s;
    stringstream ss(str);
    while(getline(ss,s,del)){
        res.push_back(stoi(s));
    }
    return res;
}

int solve(int cnt, int height){
    //cout<<cnt<<" "<<height<<" "<<'\n';
    if(height<0) return 0;
    if(cnt<0)return height==0?1:0;
    int & res = cache[cnt][height];
    if(res!=-1)return res;
    res=0;
    res+=solve(cnt-1,height);
    for(int i=0;i<blocks[cnt].size();++i){
        res+=solve(cnt-1,height-blocks[cnt][i]);
        res%=10007;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>h;
    cin.ignore();
    for(int i=0;i<n;++i){
        string str;
        getline(cin,str);
        blocks.push_back(split(str,' '));
    }
    memset(cache,-1,sizeof(cache));
    cout<<solve(n-1,h);
    return 0;
}
/*
1.
solve(n,h)=n번 학생이 블록을 놓았을 때 높이 h인 탑을 만드는 경우의 수
solve(n,h)=SUM(solve(n-1,h-blockH))
n<0 && h!=0 return 0;
else return 1;
*/