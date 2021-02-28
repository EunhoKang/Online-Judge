#include <string>
#include <vector>
#include <iostream>

using namespace std;

void turn_gear(string & gears, int num, int is_left){
    if(is_left)gears=gears.substr(1,7)+gears[0];
    else gears=gears[7]+gears.substr(0,7);
}

int main(){
    string gears[4];
    for(int i=0;i<4;++i)cin>>gears[i];
    int N; vector<vector<int>> cmd;
    cin>>N;
    for(int i=0;i<N;++i){
        int a,b;
        cin>>a>>b;
        vector<int> temp={a-1,(b==-1?1:0)};//left or right
        cmd.push_back(temp);
    }
    for(int i=0;i<N;++i){
        int gear_num=cmd[i][0],is_left=cmd[i][1];
        int ns_move[3];
        ns_move[0]=(gears[0][2]==gears[1][6]?0:1);
        ns_move[1]=(gears[1][2]==gears[2][6]?0:1);
        ns_move[2]=(gears[2][2]==gears[3][6]?0:1);
        switch(gear_num){
            case 0:{
                turn_gear(gears[0],0,is_left);
                if(!ns_move[0]) break;
                else{
                    turn_gear(gears[1],1,!is_left);
                    if(!ns_move[1]) break;
                    else{
                        turn_gear(gears[2],2,is_left);
                        if(!ns_move[2]) break;
                        else{
                            turn_gear(gears[3],3,!is_left);
                            break;
                        }
                    }
                }
            }
            case 1:{
                turn_gear(gears[1],1,is_left);
                if(!ns_move[0] && !ns_move[1])break;
                else if(ns_move[0] && !ns_move[1]){
                    turn_gear(gears[0],0,!is_left);
                    break;
                }
                else if(!ns_move[0] && ns_move[1]){
                    turn_gear(gears[2],2,!is_left);
                    if(!ns_move[2]) break;
                    else{
                        turn_gear(gears[3],3,is_left);
                        break;
                    }
                }
                else{
                    turn_gear(gears[0],0,!is_left);
                    turn_gear(gears[2],2,!is_left);
                    if(!ns_move[2]) break;
                    else{
                        turn_gear(gears[3],3,is_left);
                        break;
                    }
                }
            }
            case 2:{
                turn_gear(gears[2],2,is_left);
                if(!ns_move[2] && !ns_move[1])break;
                else if(ns_move[2] && !ns_move[1]){
                    turn_gear(gears[3],3,!is_left);
                    break;
                }
                else if(!ns_move[2] && ns_move[1]){
                    turn_gear(gears[1],1,!is_left);
                    if(!ns_move[0]) break;
                    else{
                        turn_gear(gears[0],0,is_left);
                        break;
                    }
                }
                else{
                    turn_gear(gears[3],3,!is_left);
                    turn_gear(gears[1],1,!is_left);
                    if(!ns_move[0]) break;
                    else{
                        turn_gear(gears[0],0,is_left);
                        break;
                    }
                }
            }
            case 3:{
                turn_gear(gears[3],3,is_left);
                if(!ns_move[2]) break;
                else{
                    turn_gear(gears[2],2,!is_left);
                    if(!ns_move[1]) break;
                    else{
                        turn_gear(gears[1],1,is_left);
                        if(!ns_move[0]) break;
                        else{
                            turn_gear(gears[0],0,!is_left);
                            break;
                        }
                    }
                }
            }
        }  
    }
    int res=0;
    if(gears[0][0]=='1') res+=1;
    if(gears[1][0]=='1') res+=2;
    if(gears[2][0]=='1') res+=4;
    if(gears[3][0]=='1') res+=8;
    cout<<res;
}

/*
1. 회전하는 자료구조. 앞뒤 추가부터 검색도 해야해서 그냥 스트링을 쓴다.
시계방향 회전시 뒤에서 빼고 앞으로 넣고, 시계반대방향이면 앞에서 빼고 뒤로 넣는다.
2. 처음 굴릴 때 어떤 바퀴가 돌아갈지 정해놓고 굴린다.
4개 바퀴는 그냥 차례로 구현하는게 빠르다.
3. 짜는데 1시간 반...좀더 노력하자.
*/