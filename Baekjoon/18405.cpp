#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>

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

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> grid;
    cin.ignore();
    for(int i=0;i<n;++i){
        string temp;
        getline(cin,temp);
        vector<int> tp=split(temp,' ');
        grid.push_back(tp);
    }
    int t; vector<int> target={0,0};
    cin>>t>>target[0]>>target[1];
    target[0]--; target[1]--;
    for(int i=0;i<t;++i){
        priority_queue<vector<int>> PQ;
        for(int a=0;a<n;++a){
            for(int b=0;b<n;++b){
                if(grid[a][b]!=0) PQ.push({-grid[a][b],a,b});
            }
        }
        while(!PQ.empty()){
            vector<int> p={PQ.top()[1],PQ.top()[2]};
            PQ.pop();
            if(p[0]-1>=0 && grid[p[0]-1][p[1]]==0) 
                grid[p[0]-1][p[1]]=grid[p[0]][p[1]];
            if(p[0]+1<n && grid[p[0]+1][p[1]]==0) 
                grid[p[0]+1][p[1]]=grid[p[0]][p[1]];
            if(p[1]-1>=0 && grid[p[0]][p[1]-1]==0) 
                grid[p[0]][p[1]-1]=grid[p[0]][p[1]];
            if(p[1]+1<n && grid[p[0]][p[1]+1]==0) 
                grid[p[0]][p[1]+1]=grid[p[0]][p[1]];
        }
        if(grid[target[0]][target[1]]!=0)break;
    }
    cout<<grid[target[0]][target[1]];
}

/*
작은수부터 전파시켜야 한다. 좌표를 전부 저장한 후 정렬한 뒤 순서대로 뽑아쓰면 된다.
굳이 우선수누이큐 쓸 필요 없이 리스트 정렬로도 가능할 듯
*/