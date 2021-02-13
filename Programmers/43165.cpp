#include <string>
#include <vector>

using namespace std;

int N,T;
vector<int> number;

int solve(int sum,int cnt){
    if(cnt==N) {
        if(sum==T) return 1;
        else return 0;
    }
    int res=0;
    res+=solve(sum+number[cnt],cnt+1);
    res+=solve(sum-number[cnt],cnt+1);
    return res;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    N=numbers.size();number=numbers; T=target;
    answer=solve(0,0);
    return answer;
}

/*
1.조합 문제이기 때문에 각 원소를 더할지 뺄지만 정하면 된다.
경우의 수는 2^20으로 백만 정도에 근접한다.
2.이게 왜 DFS?
*/