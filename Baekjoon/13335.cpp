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
    queue<int> truck;
    queue<int> bridge;
    int n,W,L;
    cin>>n>>L>>W;
    for(int i=0;i<L;++i){
        bridge.push(0);
    }
    string temp; cin.ignore();
    getline(cin,temp);
    vector<int> tp=split(temp,' ');
    for(int i=0;i<tp.size();++i){
        truck.push(tp[i]);
    }
    int currentW=0;
    int cnt=0;
    while(!(truck.empty() && bridge.empty())){
        if(!truck.empty() && currentW+truck.front()-bridge.front()<=W){
            currentW=currentW+truck.front()-bridge.front();
            bridge.push(truck.front());
            truck.pop();
            bridge.pop();
        }else{
            currentW=currentW-bridge.front();
            if(!truck.empty())bridge.push(0);
            bridge.pop();
        }
        cnt++;
    }
    cout<<cnt;
}

/*
1. 트럭은 큐로 계산. 다리 위에 있는 트럭도 큐로 계산.
무게는 따로 저장하고, 빈 공간은 0 삽입. 계속해서 빼고 삽입해서 0외 다른 수가 나오면 총량에서 뺌
만약 트럭이 올라오기 시작하면 그 트럭 무게 삽입하고 무게 추가, 아닐 경우 0 삽입.
근데 0일 경우 더하고 빼도 문제 없으므로 굳이 경우 나눌 필요 없다.
2.한 대의 트럭이 빠지는 순간 다른 트럭이 들어올 수 있다.
*/