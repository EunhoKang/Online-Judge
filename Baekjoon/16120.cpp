#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int idx = 0;
    string chk = "";
    for (int i = 0; i < str.length(); i++){
        chk += str[i];
        if (chk.length() >= 4){
            string now = chk.substr(chk.length()-4,4);
            if (now == "PPAP"){
                for(int i=0;i<4;++i)chk.pop_back();
                chk += "P";
            }
        }
    }
    if (chk == "P" || chk == "PPAP"){
        cout << "PPAP"; return 0;
    }
    cout << "NP";
}
/*
1.string도 스택처럼 사용이 가능하다.
*/