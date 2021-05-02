#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
string word;
int alpha[26];
string makestr="";

void MakeAnagram(int cnt){
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
        for(int i=0;i<26;++i)alpha[i]=0;
        cin>>word;
        for(int i=0;i<word.size();++i)alpha[word[i]-'a']++;
        MakeAnagram(0);
    }
    return 0;
}
/*
1.같은 알파벳은 한번만 출력해야 한다.
일일이 뽑는것보다 전부 만들어보고 정렬 후 중첩을 제거하는게 빠를 것 같다.
주어진 단어의 모든 문자를 서로 다른 원소로 보고 조합을 짜 만든다.
---
메모리 초과. 위에 제시한 방법은 사용할 수 없다.
어차피 애너그램은 사전순으로 뽑히니 전부 모아 거르지 말고 이전 애너그램을 저장하는 방식으로 걸러내도록 하자.
---
전부 안된다. 아예 일부 중복이 가능한 백트래킹 방식을 사용해야 한다.
소문자로만 만드는 점을 이용해 각 문자가 몇번 등장했는지를 각각 세는 식으로 하자.

*/