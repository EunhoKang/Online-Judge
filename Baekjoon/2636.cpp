#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> split(string s, char del){
    vector<int> res;
    stringstream ss(s);
    string tp;
    while(getline(ss,tp,del)){
        res.push_back(stoi(tp));
    }
    return res;
}

int H, W;
int cheese[100][100];
int visit[100][100];
vector<vector<int>> melt;

void Reset(){
    for(int i=0;i<100;++i)for(int j=0;j<100;++j)visit[i][j]=0;
}

void DFS(int x, int y){
    if(visit[x][y]==1) return;
    else visit[x][y]=1;
    if(cheese[x][y]==1) {
        melt.push_back({x,y});
        return;
    }else{
        if(x-1>=0) DFS(x-1,y);
        if(x+1<H) DFS(x+1,y);
        if(y-1>=0) DFS(x,y-1);
        if(y+1<W) DFS(x,y+1);
    }
}

void Melt(){
    for(int i=0;i<melt.size();++i){
        cheese[melt[i][0]][melt[i][1]]=0;
    }
}

int main(){
    cin>>H>>W;
    cin.ignore();
    for(int i=0;i<H;++i){
        string temp;
        getline(cin,temp);
        vector<int> tp=split(temp,' ');
        for(int j=0;j<W;++j){
            cheese[i][j]=tp[j];
        }
    }
    int t=0;
    int lastcheese=0;
    while(true){
        DFS(0,0);
        if(melt.size()==0) break;
        lastcheese=melt.size();
        t++;
        Melt();
        Reset();
        melt={};
    }
    cout<<t<<'\n';
    cout<<lastcheese;
}

/*
1. 깊이우선탐색으로 모든 칸을 방문한다.
2. 치즈를 만나거나 이미 방문한 칸을 만나면 탐색을 중단한다.
치즈를 만나면 해당 칸을 목록에 저장한다.
3. 발견한 치즈가 0개라면 탐색 중지, 있다면 녹이고 t++
4. 칸 수가 100이므로 사실 뭘해도 된다.
*/