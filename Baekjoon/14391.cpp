#include <bits/stdc++.h>
using namespace std;
#define ll long long

int h,w;
int paper[4][4];

int FastestGrid(vector<vector<int>> grid){
    for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[i].size();++j){
            if(!grid[i][j])return 10*i+j;
        }
    }
    return -1;
}

int SumOfGrid(vector<vector<int>> grid){
    int fastest=FastestGrid(grid);
    if(fastest==-1){
        return 0;
    }
    int x=fastest/10,y=fastest%10;
    int sum=paper[x][y];
    int res=sum;
    grid[x][y]=1;
    for(int i=1;x+i<h;++i){
        if(grid[x+i][y])break;
        for(int j=1;j<=i;++j)grid[x+j][y]=1;
        sum*=10; sum+=paper[x+i][y];
        res=max(res,sum+SumOfGrid(grid));
        for(int j=1;j<=i;++j)grid[x+j][y]=0;
    }
    sum=paper[x][y];
    for(int i=1;y+i<w;++i){
        if(grid[x][y+i])break;
        for(int j=1;j<=i;++j)grid[x][y+j]=1;
        sum*=10; sum+=paper[x][y+i];
        res=max(res,sum+SumOfGrid(grid));
        for(int j=1;j<=i;++j)grid[x][y+j]=0;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>h>>w;
    for(int i=0;i<h;++i){
        string temp;
        cin>>temp;
        for(int j=0;j<w;++j)paper[i][j]=temp[j]-'0';
    }
    vector<vector<int>> grid;
    for(int i=0;i<h;++i){
        vector<int> temp;
        for(int j=0;j<w;++j)temp.push_back(0);
        grid.push_back(temp);
    }
    cout<<SumOfGrid(grid);
    return 0;
}
/*
1.전체 경우의 수는 각 정사각형 사이의 변을 선택하는 모든 경우의 수이므로
최대 2^24이다. 2^10=>1000이므로 1억이 넘지 않을 것을 예측할 수 있다.
직사각형으로 잘라야 하므로 실제 개수는 해당 수들보다 더 적다.
2.순서를 고려하지 않고 자르기 때문에 조합으로 구해야 한다.
각 조각을 만드는 순서가 반드시 정해져 있어야 한다.
좌측 상단부터 만드는 것으로 정한다.
-----
시간 초과.
접근은 좋았으나 겹치게 세는 부분이 너무 많았다.
1x1짜리 칸을 반복문 안에서 두번 세도록 하는 것이 시간초과를 불렀다.
겹치게 세는 것이 없도록 세심히 신경써야 했다.
https://imnotabear.tistory.com/272
*/