#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    stack<int> K;
    stack<int> Q;
    
    int cnt=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='('){
            K.push(s[i-1]-'0');
            Q.push(cnt-1);
            cnt=0;
        }else if(s[i]==')'){
            cnt=Q.top()+K.top()*cnt;
            K.pop(); Q.pop();
        }else{
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

/*
1.괄호를 스택을 넣을 때 바로 앞 숫자를 다른 스택에 같이 저장, 뺄 때도 같이 뺀다.
2.길이만 계산해서 내면 되므로 뺄때마다 길이를 갱신한다.
*/