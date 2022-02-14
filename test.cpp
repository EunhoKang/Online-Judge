#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

struct Node{
    int x;
    int y;
};

int h,w;
int grid[1000][1000];
int dirx[8]={-1,-1,0,1,1,1,0,-1};
int diry[8]={0,1,1,1,0,-1,-1,-1};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>h>>w;
    for(int i=0;i<h;++i){
        string s;
        cin>>s;
        for(int j=0;j<w;++j){
            if(s[j]=='.')grid[i][j]==0;
            else grid[i][j]=s[j]-'0';
        }
    }
    int turn=0;
    int collasped=1;
    while(collasped){
        collasped=0;
        queue<Node> q;
        queue<Node> del;
        q.push({1,1});
        while(!q.empty()){
            Node node=q.front();
            q.pop();
            int empty=0;
            for(int i=0;i<8;++i){
                empty+=(grid[node.x+dirx[i]][node.y+diry[i]]==0? 1:0);
                if(0<=node.x+dirx[i]&&node.x+dirx[i]<h&&0<=node.y+diry[i]&&node.y+diry[i]<w){
                    //
                }
            }
            if(grid[node.x][node.y]>0){
                //
            }
        }
        turn++;
    }
    cout<<turn-1;
    return 0;
}
/*
1. 기존 lis에서 살짝 변형
*/

/*
vector<string> split(string str,char del){
    vector<string> res;
    string s;
    stringstream ss(str);
    while(getline(ss,s,del)){
        res.push_back(s);
    }
    return res;
}
*/