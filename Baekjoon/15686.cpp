#include <bits/stdc++.h>
using namespace std;

int n,m;
int grid[51][51];
vector<vector<int>> house;
vector<vector<int>> chicken;
int res=987654321;

int Calculate(vector<vector<int>> pick){
    int sum=0;
    for(int i=0;i<house.size();++i){
        int less=987654321;
        for(int j=0;j<pick.size();++j){
            less=min(less,abs(pick[j][0]-house[i][0])+abs(pick[j][1]-house[i][1]));
        }
        sum+=less;
    }
    return sum;
}

void pickChicken(int cnt, vector<vector<int>> pick,int start){
    if(cnt>=m){
        res=min(res,Calculate(pick));
        return;
    }
    for(int i=start;i<chicken.size();++i){
        vector<vector<int>> temp=pick;
        temp.push_back(chicken[i]);
        pickChicken(cnt+1, temp, i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>grid[i][j];
            if(grid[i][j]==1)house.push_back({i,j});
            else if(grid[i][j]==2)chicken.push_back({i,j});
        }
    }
    vector<vector<int>> pick;
    pickChicken(0, pick, 0);
    cout<<res;
    return 0;
}
/*
1.모든 과정을 완전탐색으로 해결할 경우, 폐업할 치킨집을 고르고, 각 집마다 치킨집을 모두 찾아가면서 거리를 계산하므로 13C6*100*13인데 천만이 넘지 않는다. 즉 완전탐색으로 충분히 구할 수 있는 크기이다.

2.치킨집 폐업을 선택할 때는 위치에 따라 오름차순 정렬 후 순서 고려 없이 뽑는다.
한 집에서 다른 집을 고르는 경우는 이미 폐업할 식당이 정해진 상황에서는 각각의 집에 대해 독립적으로 시행되므로 각 경우에서 최소값을 뽑는다.
*/