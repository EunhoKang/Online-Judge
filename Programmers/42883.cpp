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
1. N이 백만까지이므로, 대략적인 시간복잡도가 O(NlgN)이하여야 한다. 브루트포스로는 못푸는 문제.

2. 앞에서부터 읽어가면서 푼다고 생각해보자. 만약 지우기 횟수가 남았는데 이전 숫자보다 큰 값이 들어온다면, 
해당 숫자를 앞자리 숫자로 쓰는게 무조건 이득이다. 더 큰 수를 결정하는 요소는 맨 앞자리 수이기 때문.
그렇다면, 해당 숫자보다 작은 앞의 모든 숫자를 전부 지우는 것이 반드시 이득이라는 뜻.
만약 k가 부족할 경우, 남은 것들 중 작은 것을 지울수록 기대값이 커진다.

3. 이 방법을 좀 더 확대하면 다음과 같은 알고리즘을 생각할 수 있다.
1) 맨 앞에서부터 하나씩 수를 읽는다.
2) 읽을 때마다 현재까지 읽은 수 중 가장 큰 수보다 큰지 확인한다.
더 크면 가장 큰 수를 업데이트하고 앞에 남겨둔 수들을 작은 것부터 지운다.
더 작으면 그대로 남겨둔다.
3) 맨뒤까지 읽으면서 횟수 k가 부족할 경우, 그대로 알고리즘을 종료한다.
4) k가 남았을 경우, 남겨진 수 중 뒤에서부터 지운다.

4. 이 기법을 쉽게 활용하기 위해 스택을 활용한다. 스위핑 알고리즘이라고도 불리는 자주 쓰이는 방법.
*/