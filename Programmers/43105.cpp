#include <string>
#include <vector>
#include <math.h>

using namespace std;

int cache[501][501];

vector<vector<int>> tri;

int n;

int solve(int y, int x){
    if(y>n) return 0; 
    int & res=cache[y][x];
    if(res!=-1) return res;
    res=tri[y-1][x-1]+max(solve(y+1,x),solve(y+1,x+1));
    return res;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    n=triangle.size();
    tri=triangle;
    for(int i=0;i<n+1;++i){
        for(int j=0;j<n+1;++j){
            cache[i][j]=-1;
        }
    }
    answer=solve(1,1);
    return answer;
}
/*
1.순서는 항상 
1)완전 탐색 만들기
2)캐싱하기(뭘 기준으로 캐싱할지, 어떻게 캐싱할지)
3)추가로 신경쓸 거 처리(범위, 순서))
2.범위 잘 신경써야 한다.
*/