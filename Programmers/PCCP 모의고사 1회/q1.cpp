#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int alphabet[26]; 

string solution(string input_string) {
    string answer = "";
    char lastchar = '0';
    for(char character : input_string)
    {
        if(lastchar == character) continue;
        alphabet[character-'a']++;
        lastchar = character;
    }
    for(int i = 0; i < 26; ++i)
    {
        if(alphabet[i] > 1) answer += ('a' + i);
    }
    if(answer == "") answer = "N";
    return answer;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solution("edeaaabbccd");
    return 0;
}

/*
1.
*/