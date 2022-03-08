#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int  l,c;
char chars[15];
string res="";
char vols[5]={'a','e','i','o','u'};

bool isVowel(char s){
    for(char vol : vols){
        if(vol==s)return true;
    }
    return false;
}

void brute(int n, int vol, int con){
    if(vol+con==l){
        if(vol>=1 && con>=2)cout<<res<<'\n';
        return;
    }
    if(n>=c)return;
    string temp=res;
    if(isVowel(chars[n])){
        res+=chars[n];
        brute(n+1,vol+1,con);
    }else{
        res+=chars[n];
        brute(n+1,vol,con+1);
    }
    res=temp;
    brute(n+1,vol,con);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>l>>c;
    for(int i=0;i<c;++i)cin>>chars[i];
    sort(chars,chars+c);
    brute(0,0,0);
    return 0;
}
/*
1.문자열은 정렬된 순서 -> 우선 문자들이 정렬된 순서에서 탐색
2.자음 둘 이상, 모음 하나 이상 -> 앞에서부터 문자를 포함시킬지 여부를 두고 뽑되, 현재 포함된 자음과 마음의 숫자를 계산.
3.최대 연산 => 2^15
*/
