#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
string words[50];
int res=0;
ll needToRead[50];
ll pick=0;
ll mask=0;

int Solve(ll unknown){
    int cnt=0;
    for(int i=0;i<n;++i)if((unknown&needToRead[i])==0)cnt++;
    return cnt;
}

void Learning(int start,int cnt){
    if(cnt==k){
        res=max(res,Solve(pick^mask));
        return;
    }
    for(int i=start;i<26;++i){
        if((pick&(1<<i))==0){
            pick+=(1<<i);
            Learning(i,cnt+1);
            pick-=(1<<i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<26;++i)mask+=(1<<i);
    pick+=(1)+(1<<('c'-'a'))+(1<<('i'-'a'))+(1<<('n'-'a'))+(1<<('t'-'a'));
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>words[i];
    if(k<5){
        cout<<0;
        return 0;
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<words[i].length();++j){
            ll temp=1<<(words[i][j]-'a');
            if((temp&needToRead[i])!=0)continue;
            needToRead[i]+=temp;
        }
    }
    
    Learning(0,5);
    cout<<res;
    return 0;
}
/*
1.a,n,t,i,c는 무조건 알아야 한다. 만약 k<=4이면 0을 출력한다.
2.모르는 글자와 문자를 전부 대응시킨다.
모르는데 문자에 있는 경우만 잡아내면 된다.
아는 문자를 전부 고른 후 전부 1로 덮인 마스크에 nor(^)연산을 취한다.
비트마스킹을 사용하여 &연산을 취하면 된다.
----
기존의 알고리즘에서 시간 초과 발생.
조합 만드는 함수를 잘 외워서 사용하자.
시간이 최과되면 가장 오래 걸리는 함수부터 접근한다.
*/