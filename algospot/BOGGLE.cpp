#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=INT_MAX;

static int dx[8]={-1,-1,-1,0,1,1,1,0};
static int dy[8]={-1,0,1,1,1,0,-1,-1};

int C;
char grid[5][5];
int n;
string str[10];

bool inGrid(int x, int y){//해당 좌표가 격자 안에 있는지
    if(0<=x && x<5 && 0<=y && y<5)return true;
    return false;
}

bool hasWord(int x, int y, string word){//x,y에서 이어진 문자열을 찾을 수 있는지 탐색
    if(word=="")return true;//찾을 문자열이 더 없으면 참
    bool res=false;
    for(int i=0;i<8;++i){//모든 칸에서 다음 단어를 찾을 수 있는지 확인, 찾을 수 없다면 false 리턴
        if(inGrid(x+dx[i],y+dy[i])&&word[0]==grid[x+dx[i]][y+dy[i]]){
            res|=hasWord(x+dx[i],y+dy[i],word.substr(1));
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>C;
    while(C--){
        for(int i=0;i<5;++i)for(int j=0;j<5;++j)cin>>grid[i][j];
        cin>>n;
        for(int i=0;i<n;++i)cin>>str[i];
        for(int i=0;i<n;++i){
            string target=str[i];
            bool result=false;
            for(int i=0;i<5;++i)for(int j=0;j<5;++j)if(grid[i][j]==target[0]){//모든 칸을 뒤져 단어를 찾을 수 있다면
                bool temp=hasWord(i,j,target.substr(1));
                if(temp){
                    result|=hasWord(i,j,target.substr(1));//되는게 하나라도 있는지 확인, 있으면 즉시 탐색 종료
                    break;
                }
            }
            cout<<target<<" "<<(result?"YES":"NO")<<'\n';
        }
    }
    return 0;
}