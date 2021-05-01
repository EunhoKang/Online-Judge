#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sudoku[9][9];
int row[9][10];
int column[9][10];
int square[3][3][10];
vector<vector<int>> blank;

void PrintSudoku(){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<'\n';
    }
}

int Solve(int cnt){
    if(cnt==blank.size()){return 1;}
    else{
        int x=blank[cnt][0];
        int y=blank[cnt][1];
        for(int i=1;i<10;++i){
            if(!row[y][i]&&!column[x][i]&&!square[x/3][y/3][i]){
                sudoku[x][y]=i;
                row[y][i]=1;
                column[x][i]=1;
                square[x/3][y/3][i]=1;
                if(Solve(cnt+1))return 1;
                sudoku[x][y]=0;
                row[y][i]=0;
                column[x][i]=0;
                square[x/3][y/3][i]=0;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cin>>sudoku[i][j];
            row[j][sudoku[i][j]]=1;
            column[i][sudoku[i][j]]=1;
            square[i/3][j/3][sudoku[i][j]]=1;
            if(sudoku[i][j]==0)blank.push_back({i,j});
        }
    }
    Solve(0);
    PrintSudoku();
    return 0;
}
/*
1.각각의 가로줄, 세로줄, 사각형에 대해 스도쿠 규칙에 맞는지 확인하는 배열을 만든다.
어떤 칸에 수를 넣을 때 넣는 순간 스도쿠 규칙에 어긋나지 않았는지 확인하며,
어긋나지 않았다면 계속 진행하고 어긋나면 다음 수로,
다음 수가 없다면 이전으로 이동한다.
*/