#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

static int dx[4]={1,-1,0,0};
static int dy[4]={0,0,1,-1};

int R,C;
char board[20][20];
int isChecked[26];

int OnBoard(int x, int y){
    if(0<=x && x<R && 0<=y && y<C)return 1;
    else return 0;
}

int count(int x, int y){
    int answer=0;
    for(int i=0;i<4;++i){
        int X=x+dx[i], Y=y+dy[i];
        if(OnBoard(X,Y)==1 && isChecked[(board[X][Y]-'A')]==0){
            isChecked[(board[X][Y]-'A')]=1;
            answer=max(answer, 1+count(X,Y));
            isChecked[(board[X][Y]-'A')]=0;
        }
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>R>>C;
    for(int i=0;i<R;++i){
        string temp;
        cin>>temp; 
        for(int j=0;j<C;++j)board[i][j]=temp[j];
    }
    isChecked[(board[0][0]-'A')]=1;
    cout<<1+count(0,0)<<'\n';
    return 0;
}


/*
1.실제로 나올수 있는 출력의 초대값은 26이므로 사실상 브루트포스를 해도 문제가 없다.
2.함수를 잘 구별해 쓰고 변수 초기화와 원상 복귀에 신경써야 합니다.
*/