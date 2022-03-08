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
1.주어진 숫자로 가장 가까운 숫자를 만들면 된다.
->우선 100인지 아닌지 체크. 아니라면 주어진 숫자로 만들 수 있는 가장 가까운 수를 만든다.
2.일반적으로 타겟된 숫자가 N자리 숫자라면, N-1~N+1자리 안에서 수를 만드는게 최소이다.
-----
틀리고 나서야 안 것 : 
100에서부터 무지성으로 누르는게 더 빠를 수도 있다. 
어차피 모든 숫자를 탐색해도 500000보다 작으므로 해도 된다.
*/