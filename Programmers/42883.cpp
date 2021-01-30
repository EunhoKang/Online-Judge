#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = ""; 
    stack<char> S;
    S.push(number[0]);
    for(int i=1;i<number.size();++i){
        if(number[i]>S.top() && k>0){
            while(!S.empty()&& k>0&&number[i]>S.top() ){
                S.pop();
                --k;
            }
            S.push(number[i]);
        }else{
            S.push(number[i]);
        }
    }
    if(k>0){
        for(int i=0;i<k;++i)S.pop();
    }
    while(!S.empty()){
        answer+=S.top();
        S.pop();
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

int main(){
    int n,k;
    string num;
    cin>>n>>k;
    cin>>num;
    cout<<solution(num,k);
}
/*
1. https://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220809919539

*/