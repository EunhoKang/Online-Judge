#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),greater<int>());
    priority_queue<int> boats;
    for(int i=0;i<people.size();++i){
        if(!boats.empty() && boats.top()>=people[i]){
            boats.pop();
            boats.push(0);
        }else{
            boats.push(limit-people[i]);
        }
    }
    answer=boats.size();
    return answer;
}

/*
1. 큰 순서 정렬
2. 앞에서부터 구명 보트에 태우기 시작한다. 한 사람이 구명보트에 탈 경우 더 탈 수 있는 무게를 계산해 우선순위 큐에 정렬.
큰 순서 정렬이므로 남는 공간이 큰 곳에 우선적으로 넣어야 한다.
3. 다음사람부터 우선순위 큐 맨 위의 값과 비교해 더 탈 수 있다면 해당 구명보트는 이제 두명이 탔으므로 남는 무게를 0으로 만든다.
4.마지막에 우선순위큐 길이 계산
*/