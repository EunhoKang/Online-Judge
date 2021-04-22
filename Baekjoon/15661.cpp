#include <bits/stdc++.h>
using namespace std;

int sinergy[20][20];
int n;
int res=987654321;

int CalculateSinergy(vector<int> team){
    int calc=0;
    for(int i=0;i<team.size();++i){
        for(int j=i+1;j<team.size();++j){
            calc+=sinergy[team[i]][team[j]]+sinergy[team[j]][team[i]];
        }
    }
    return calc;
}

int Calc(vector<int> picked){
    vector<int> A,B;
    for(int i=0;i<n;++i){
        if(picked[i])A.push_back(i);
        else B.push_back(i);
    }
    return abs(CalculateSinergy(A)-CalculateSinergy(B));
}

void Pick(int cnt,vector<int> pick,int last){
    if(cnt>=n/2) {
        res=min(Calc(pick),res);
        return;
    }
    for(int i=last;i<n;++i){
        if(!pick[i]){
            pick[i]=1;
            Pick(cnt+1,pick,i);
            pick[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    memset(sinergy, 0, sizeof(sinergy));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>sinergy[i][j];
    vector<int> pick;
    for(int i=0;i<n;++i)pick.push_back(0);
    Pick(0,pick,0);
    cout<<res;
    return 0;
}
/*
1.
쌍을 이뤄 값을 더하는 방식의 경우 팀원의 수가 커질수록 시너지 값이 매우 크게 상승한다. 따라서 팀원의 차이를 최소화해야 한다.
20명 중 10명만을 골라내는 경우 20C10=184756이므로 시간안에 계산이 가능하다. 
----
모든 경우를 계산해야 하는 듯하다.
이 방법으로도 풀렸지만 해당 문제에서만 쓰이는 편법이다.
*/