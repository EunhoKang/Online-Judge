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
    //숫자 입력을 통해 얻을 수 있는 자연수에서 N으로 변환하는 입력의 최소값을 구한다. 
    if(remoteNum.length()>0){
        //버튼 입력이 최소인지 확인
        res=min(abs(stoi(remoteNum)-N)+n,res);
    }
    if(n>=targetN){
        //채널 번호는 최대 500000이므로 6자리까지만 고려하면 된다.
        return;
    }else{
        string temp=remoteNum;
        for(int i=0;i<10;++i){//모든 입력 가능한 수에 대해 차례대로 시도한다.
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
    if(N==100)cout<<0;//만약 N이 100이면 입력 없이 바로 끝난다.
    else{
        brute(0,7);
        cout<<min(res,abs(N-100));//100에서 바로 +-로 이동할 경우가 입력 횟수가 더 적을 수도 있으므로 확인한다.
    }
    return 0;
}

/*
1.주어진 숫자로 가장 가까운 숫자를 만들면 된다.
->우선 100인지 아닌지 체크. 아니라면 주어진 숫자로 만들 수 있는 가장 가까운 수를 만든다.
-----
틀리고 나서야 안 것 : 
100에서부터 무지성으로 누르는게 더 빠를 수도 있다. 
어차피 모든 숫자를 탐색해도 500000보다 작으므로 범위 내 모든 수를 전부 비교해도 된다.
*/