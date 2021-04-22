#include <bits/stdc++.h>
using namespace std;

vector<int> split(string str,char del){
    vector<int> res;
    string s;
    stringstream ss(str);
    while(getline(ss,s,del)){
        res.push_back(stoi(s));
    }
    return res;
}
int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int I=0;I<N;++I){
        string command;
        int n;
        string array;
        cin>>command;
        cin>>n;
        cin>>array;
        vector<int> arr=split(array.substr(1,array.size()-2),',');
        deque<int> dq;
        bool isFlip=false;
        bool print=true;
        for(int i=0;i<arr.size();++i){
            dq.push_back(arr[i]);
        }
        for(int i=0;i<command.size();++i){
            if(command[i]=='R'){
                isFlip=!isFlip;
            }else{
                if(dq.empty()){
                    print=false;
                    cout<<"error"<<"\n";
                    break;
                }
                if(isFlip) dq.pop_back();
                else dq.pop_front();
            }
        }
        if(print){
            cout<<"[";
            if(isFlip){
                deque<int> temp;
                while(!dq.empty()){
                    temp.push_back(dq.back());
                    dq.pop_back();
                }
                dq=temp;
            }
            while(!dq.empty()){
                cout<<dq.front();
                dq.pop_front();
                if(!dq.empty())cout<<',';
            }
            cout<<"]"<<"\n";
        }
    }
    return 0;
}
/*
1.뒤집는 작업과 맨앞에서 지우는 작업이 동시에 있다. 덱을 사용.
2.직접 뒤집으면 시간이 초과되니 뒤집어진 상태를 불 변수로 잡고 뒤집혀 있으면 뒤에서, 아닐 경우 앞에서 pop을 하면 된다. 출력하기 전에 한번만 뒤집는다. 주어진 시간은 1초인데 최악의 경우 1조번의 연산을 하기 때문에 직접 뒤집는 연산은 하지 않는다.
3.https://jaimemin.tistory.com/838
*/