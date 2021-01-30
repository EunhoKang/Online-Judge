#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
int dist[21][21];

int allChecked(vector<int> pick){
    for(int i=0;i<pick.size();++i) if(!pick[i]) return 0;
    return 1;
}

int solution(string name) {
    int answer = 0;
    vector<int> point;
    vector<int> pick;
    int picknum=0;
    //#1 상하 계산
    for(int i=0;i<name.size();++i){
        int tp=1;
        if(name[i]!='A'){
            point.push_back(i);
            tp=0;
            answer+=min(('Z'-name[i]+1) , (name[i]-'A'));
        }
        pick.push_back(tp);
    }
    //#2 미리 각 위치별 거리 계산
    for(int i=0;i<name.size();++i){
        for(int j=0;j<name.size();++j){
            int ab=abs(i-j);
            if(i<j){
                dist[i][j]=min(ab,(int)(name.size()-ab));
            }else{
                dist[i][j]=ab;
            }
        }
    }
    int start=0;
    pick[start]=1;
    //#1 좌우 계산
    while(!allChecked(pick)){
        int res=100;
        int next=0;
        vector<int> Q;
        for(int i=0;i<name.size();++i){
            if(pick[i] || dist[start][i]==0) continue;
            if(res>=dist[start][i]){
                res=dist[start][i];
                Q.push_back(i);
            }
        }
        //#2 만약 좌우 거리가 같다면 오른쪽 선택
        if(Q.size()>1){
            if(Q[0]<start)next=Q[1];
            else next=Q[0];
        }else{
            next=Q[0];
        }
        pick[next]=1;
        answer+=res;
        start=next;
    }
    
    return answer;
}
/*
1.조이스틱 조작시 각 이동이 개별적으로 발생할 수 있으므로, 따로 계산해도 된다.
2.매 순간 양쪽 스틱 중 가장 가까운 곳으로 이동해야 한다.
단, 화면 끝을 오갈 시 방향이 일방적이므로 거리가 같으면 오른쪽을 선택한다.
*/