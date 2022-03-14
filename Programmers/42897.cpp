#include <string>
#include <vector>
#include <math.h>

using namespace std;

int cache[1000000];
vector<int> m;

int solve(int N,int house){
    if(house>=N) return 0;
    int & res = cache[house];
    if(res!=-1) return res;
    res=m[house]+max(solve(N,house+2),solve(N,house+3));//한칸 혹은 두칸 건너뜀
    return res;
}

int solution(vector<int> money) {
    int answer = 0;
    m=money;
    m.erase(m.end());//0번 시작은 마지막 원소에 접근 불가능.
    int N=m.size();
    for(int i=0;i<N;++i) cache[i]=-1;//메모리 초기화
    answer=solve(N,0);//0번 시작
    m=money; N=m.size();
    for(int i=0;i<N;++i) cache[i]=-1;//메모리 초기화
    answer=max(answer,solve(N,1));//1번 시작
    for(int i=0;i<N;++i) cache[i]=-1;//메모리 초기화
    answer=max(answer,solve(N,2));//2번 시작
    return answer;
}

/*는
1.일단 최대 갯수 털어야 이득이므로 턴 두 집의 사이 거리는 반드시 두칸 혹은 한칸.
2.solve(int n)=n번집을 선택했을 때 모든집을 털었을 시 얻을 수 있 최대값
solve(n)=money[n]+max(solve(n+2),solve(n+3))
3.원형 보정을 해줘야 한다. 0,1,2번 집에서부터 시작한다고 가정했을 때,
0번 집을 털 경우 n-1번 집은 선택할 수 없으므로 이에 대한 계산을 따로 한다.
나머지 경우는 선형으로 가정하고 진행하며, 세 번의 계산 중 최대값을 구한다.
3번 해봐야 3*1000000 이므로 시간안에 충분히 계산이 가능하다.
*/