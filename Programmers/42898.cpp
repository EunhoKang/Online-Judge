#include <string>
#include <vector>
#include <math.h>

using namespace std;

int cache[101][101];

int pud[101][101];

int N,M;

int solve(int y, int x){
    if(y>N || x>M) return 0; 
    if(y==N && x==M) return 1;
    int & res=cache[y][x];
    if(res!=-1) return res;
    if(pud[y][x]) return res=0;
    res=solve(y+1,x)+solve(y,x+1);
    return res;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    N=n,M=m;
    for(int i=0;i<n+1;++i){
        for(int j=0;j<m+1;++j){
            cache[i][j]=-1;
        }
    }
    for(int i=0;i<puddles.size();++i){
        pud[puddles[i][1]][puddles[i][0]]=1;
    }
    answer=solve(1,1);
    return answer;
}