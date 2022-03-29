#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
string word;
int alpha[26];
string makestr="";

void MakeAnagram(int cnt){//등장한 알파벳들로 길이가 같은 문자열을 만들어 출력. 정렬 순서만 만져주면 반드시 알파벳순으로 나온다.
    if(cnt==word.size()){
        cout<<makestr<<'\n';
        return;
    }else{
        for(int i=0;i<26;++i){
            if(alpha[i]>0){
                alpha[i]--;
                makestr+=char('a'+i);
                MakeAnagram(cnt+1);
                alpha[i]++;
                makestr.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int I=0;I<N;++I){
        for(int i=0;i<26;++i)alpha[i]=0;//초기화
        cin>>word;
        for(int i=0;i<word.size();++i)alpha[word[i]-'a']++;//각 알파벳 등장 횟수 세기
        MakeAnagram(0);
    }
    return 0;
}
/*
1.애너그램 개수가 십만개 이하로 제한되어 있으므로 완전탐색류가 무조건 가능하다. 죄다 뽑아야 하는 문제라 백트래킹을 활용.
2.중복을 고려하는 문제로 단어를 알파벳별로 끊어서 분류한 후 조합하는 방식을 쓴다..
*/