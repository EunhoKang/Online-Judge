#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),greater<int>());
    int h=1;
    while(h<=citations.size()){
        int i=0;
        while(citations[i]>=h && i<=h-1){
            if(i>h-1) break;
            i++;
        }
        if(i<h)break;
        h++;
    }
    answer=h-1;
    return answer;
}


/*
1. https://www.ibric.org/myboard/read.php?Board=news&id=270333
설명이 뭔....
2.그냥 이진 탐색 쓸걸 그랬다
*/