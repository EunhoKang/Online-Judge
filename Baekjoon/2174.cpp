#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Turn(int left, int dir){
    if(left){
        dir--;
        dir=dir<0?dir+4:dir;
    }else{
        dir++;
        dir=dir>3?dir-4:dir;
    }
    return dir;
}

vector<int> AttemptMove(vector<int> r){
    int dir=r[2];
    int x=r[0]; int y=r[1];
    vector<int> next={-1,-1};
    if(dir==0){
        next[0]=x;
        next[1]=y+1;
    }
    else if(dir==1){
        next[0]=x+1;
        next[1]=y;
    }
    else if(dir==2){
        next[0]=x;
        next[1]=y-1;
    }
    else if(dir==3){
        next[0]=x-1;
        next[1]=y;
    }
    return {next[0],next[1],dir,r[3]};
}

vector<int> binding(vector<int> r) {
    return {101-r[1],r[0],r[2],r[3]};
}

int W,H;
vector<int> Grid[102][102];
vector<int> Table[102];

int main(){
    for(int i=0;i<101;++i)for(int j=0;j<101;++j)Grid[i][j]={0,0,0,0};
    cin>>W>>H;
    int N,M;
    cin>>N>>M;
    int id=1;
    for(int i=0;i<N;++i){
        int x,y; string dir;
        cin>>x>>y>>dir;
        int _dir;
        if(dir=="N") _dir=0;
        else if(dir=="E") _dir=1;
        else if(dir=="S") _dir=2;
        else if(dir=="W") _dir=3;
        vector<int> r={x,y,_dir,id};
        vector<int> b=binding(r);
        Grid[b[0]][b[1]]=r;
        Table[id]=r;
        id++;
    }
    vector<vector<int>> Commands;
    for(int i=0;i<M;++i){
        int id,rec; string cmd;
        cin>>id>>cmd>>rec;
        int _cmd;
        if(cmd=="L") _cmd=0;
        else if(cmd=="R") _cmd=1;
        else if(cmd=="F") _cmd=2;
        Commands.push_back({id,_cmd,rec});
    }
    for(int i=0;i<M;++i){
        int id=Commands[i][0],cmd=Commands[i][1],rec=Commands[i][2];
        for(int j=0;j<rec;++j){
            if(cmd==0){
                Table[id][2]=Turn(1,Table[id][2]);
            }
            else if(cmd==1){
                Table[id][2]=Turn(0,Table[id][2]);
            }
            else{
                vector<int> next=AttemptMove(Table[id]);
                vector<int> b=binding(next);
                if(next[0]<1 || W<next[0] || next[1]<1 || H<next[1]){
                    cout<<"Robot "<<id<<" crashes into the wall"<< '\n';
                    return 0;
                }else{
                    if(Grid[b[0]][b[1]][3]!=0){
                        cout<<"Robot "<<id<<" crashes into robot "<<(Grid[b[0]][b[1]][3])<< '\n';
                        return 0;
                    }
                    else{
                        vector<int> tb=binding(Table[id]);
                        vector<int> temp=Grid[tb[0]][tb[1]];
                        Grid[tb[0]][tb[1]]=Grid[b[0]][b[1]];
                        Grid[b[0]][b[1]]=temp;
                        Table[id]={next[0],next[1],next[2],next[3]};
                    }
                }
            }
        }
    }
    cout<<"OK\n";
}

/*
1. 로봇에 바로 명령을 해야 하므로 각 로봇을 배열에 저장한다.
2. 로봇간의 충돌을 확인해야 하므로 충돌 여부 조사를 위해 좌표계를 구현한다.
3. 좌표계와 배열 표현이 상하반전임을 인지한다. 또한 x,y좌표가 반대이다.
좌표를 배열에 대입할 때는 바인딩 함수로 값을 변환하여 계산한다.
*/