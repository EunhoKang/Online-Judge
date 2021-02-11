#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> cache[8];

int solution(int N, int number) {
    int answer = 0;
    for(int i=0; i<8; ++i){
        int tp=N;
        for(int j=0;j<i;++j) tp=tp*10+N;
        if(tp==number) return answer=i+1;
        cache[i].push_back(tp);
        for(int j=0;j<i;++j){
            for(int k=0;k<cache[j].size();++k){
                int temp=cache[j][k];
                for(int l=0; l<cache[i-j-1].size();++l){
                    int sum; 
                    sum=temp+cache[i-j-1][l];
                    if(sum==number) return answer=i+1;
                    cache[i].push_back(sum);
                    sum=temp-cache[i-j-1][l];
                    if(sum==number) return answer=i+1;
                    cache[i].push_back(sum);
                    sum=temp*cache[i-j-1][l];
                    if(sum==number) return answer=i+1;
                    cache[i].push_back(sum);
                    if(cache[i-j-1][l]>0){
                        sum=temp/cache[i-j-1][l];
                        if(sum==number) return answer=i+1;
                        cache[i].push_back(sum);
                    }
                }
            }
        }

    }
    answer=-1;
    return answer;
}

/*
1.https://hazung.tistory.com/61
계산 과정이 재귀적으로 이루어짐을 이용한다.
8을 5번 쓴 계산 결과는 8을 N번 사용한 결과와 8을 5-N번 사용한 결과의 연산합으로 표현됨을 이용하여 낮은숫자부터 차례대로 캐싱하면 된다.
실제로 돌려보면 최악의 경우 실행시간이 8초 근처인데 그냥 해시테이블 써도 될듯.
*/