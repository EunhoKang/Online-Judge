#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string,int> m;
    for(int i=0;i<clothes.size();++i){
        if(m.find(clothes[i][1])==m.end()){
            m.insert(make_pair(clothes[i][1],1));
        }else{
            m[clothes[i][1]]++;
        }
    }
    int res=1;
    unordered_map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        res*=(it->second+1);
    }
    answer=res-1;
    return answer;
}

/*
1.경우의 수는 다음과 같다.
1)각 종류마다 옷을 입거나(n개)), 안입거나.
2)아무것도 안 입는 경우는 제외해야 한다. (-1)
a,b,c,d가 차례대로 얼굴,상의,하의,자켓의 종류 수라면
(a+1)(b+1)(c+1)(d+1)-1 이 답이다.
다만 종류가 여러개일 가능성이 있으니 전부 맵으로 저장해야 한다.
*/