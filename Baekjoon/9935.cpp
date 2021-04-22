#include <iostream>
#include <string>

using namespace std;

const int MAX = 1000000 + 1;
string s, bomb;
char result[MAX];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s>>bomb;
    int idx = 0;

    for(int i = 0; i < s.length(); i++){
        result[idx++] = s[i];
        if(result[idx - 1] == bomb[bomb.length() - 1]){
            if(idx - bomb.length() < 0)continue;
            bool detected = true;
            for(int j=0; j < bomb.length(); j++)
                if(result[idx - j - 1] != bomb[bomb.length() - j - 1]){
                    detected =false;
                    break;
                }
            if(detected)idx -= bomb.length();
        }

    }

    if(!idx)cout<<"FRULA\n";
    else{
        for(int i = 0; i < idx; i++)cout<<result[i];
        cout<<"\n";
    }
    return 0;
}

/*
1.폭발 문자열과 앞문자가 같다면 저장을 시작하고, 
만약 다음 문자가 폭발문자열의 첫문자 혹은 두번째 문자와 다르면 스택을 비운다.
만약 현재 스택의 top에 있는 문자를 폭발 문자열의 k번째 문자라고 할 때,
마찬가지로 n번째 문자가 폭발 문자열의 첫번째 혹은 k+1번째 문자인지만 체크한다.
2.폭발 문자열의 마지막 문자열이 저장되면 즉시 스택을 전부 지운다.
이때 폭발 문자열은 서로 다른 문자로 되어 있으므로 마지막 문자만 기억한다.
3.스택으로 문자 단위로 저장하면 시간초과가 되므로 문자열로 저장한다.

--------
스택 안쓰고 그냥 인덱스로 풀면 된다.

순서대로 글자 추가하다가 폭탄 마지막 글자를 찾으면 거꾸로 가면서 폭탄이 맞는지 확인,
맞으면 인덱스를 줄이고 끝날때까지 반복

https://jaimemin.tistory.com/823
*/