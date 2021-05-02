#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
string s;
vector<char> cal;
vector<int> number;
ll res=-998877665544332211;

ll Calculate(vector<int> pick){
    ll sum=number[0];
    if(number.size()<2) return sum;
    int cp=0; int np=1;
    while(cp<=cal.size()){
        if(pick[np]){
            int tp=number[np];
            np++;
            if(cal[cp+1]=='+')tp+=number[np];
            else if(cal[cp+1]=='-')tp-=number[np];
            else if(cal[cp+1]=='*')tp*=number[np];
            if(cal[cp]=='+')sum+=tp;
            else if(cal[cp]=='-')sum-=tp;
            else if(cal[cp]=='*')sum*=tp;
            cp++;
        }
        else{
            if(cal[cp]=='+')sum+=number[np];
            else if(cal[cp]=='-')sum-=number[np];
            else if(cal[cp]=='*')sum*=number[np];
        }
        cp++;
        np++;
    }
    return sum;
}

void Pick(int cnt, int brcnt, vector<int> pick,int start){
    if(cnt>=brcnt){
        res=max(res,Calculate(pick));
        return;
    }
    for(int i=start;i<number.size()-1;++i){
        pick[i]=1;
        Pick(cnt+1,brcnt,pick,i+2);
        pick[i]=0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*')cal.push_back(s[i]);
        else number.push_back((int)(s[i]-'0'));
    }
    vector<int> pick;
    for(int i=0;i<number.size();++i)pick.push_back(0);
    for(int i=0;i<=(n+1)/4;++i)Pick(0,i,pick,0);
    cout<<res;
    return 0;
}
/*
1.연산자 수는 최대 10개이다. 10!=3628800이므로 시간 안에 계산이 가능하다.
2.정답이 2^31~-2^31이므로 lon long 형을 사용한다.
3.추가할 수 있는 최대 괄호의 수는 (n+1)/4이다.
괄호를 넣을 경우 반드시 뒤의 수식 하나를 계산하게 된다. 이를 미리 계산하도록 프로그램을 작성한다.
괄호를 넣을 때는 두칸을 넘겨야 한다. 한칸만 넘기면 연산자가 둘 이상 괄호 안에 들어갈 수 있기 때문. 또한 숫자를 기준으로 괄호를 씌웠기 때문에 마지막은 세지 않는다.
----
글자 하나만 들어가는 가장 작은 값에 대한 경우를 처리하지 못했다.

또한 모든 테스트 케이스가 음수가 되는 경우도 있기 때문에
res를 음수로 초기화했어야 한다.
*/