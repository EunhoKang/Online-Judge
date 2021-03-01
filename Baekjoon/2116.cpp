#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <math.h>

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

int N;
vector<vector<vector<int>>> Dice;
int cache[7][10000];

int DiceSum(int startnum,int dicenum){
    if(dicenum>=N) return 0;
    int & res=cache[startnum][dicenum];
    if(res!=-1) return res;
    res=0;
    int nextnum=0;
    for(int i=0;i<3;++i){
        for(int j=0;j<2;++j){
            if(Dice[dicenum][i][j]==startnum){
                nextnum=Dice[dicenum][i][(j==1?0:1)];
            }
        }
    }
    for(int i=6;i>0;--i){
        if(i==nextnum || i==startnum) continue;
        res=i;
        break;
    }
    return res+=DiceSum(nextnum, dicenum+1);
}

int solution(){
    int res=0;
    for(int i=1;i<=6;++i){
        res=max(res,DiceSum(i,0));
    }
    return res;
}

int main(){
    for(int i=0;i<7;++i)for(int j=0;j<10000;++j)cache[i][j]=-1;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;++i){
        string temp;
        getline(cin,temp);
        vector<int> tp=split(temp,' ');
        Dice.push_back({{tp[0],tp[5]},{tp[1],tp[3]},{tp[2],tp[4]}});
    }
    cout<<solution();
}

/*
1.주사위 쌓는 순서가 고정되어 있어서 각 시간이 거의 걸리지 않는다. 완전탐색 사용.
2.첫 주사위의 바닥을 결정하고 각 단계마다 옆면의 최대값을 구한다.
이후 해당 값의 총합들 중 가장 큰 경우를 구한다.
*/