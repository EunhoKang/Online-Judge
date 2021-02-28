#include <string>
#include <vector>
#include <iostream>
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

int main(){
    int D,N;
    vector<int> Oven;
    vector<int> Dows;
    cin>>D>>N;
    cin.ignore();
    string temp;
    getline(cin,temp);
    Oven=split(temp,' ');
    getline(cin,temp);
    Dows=split(temp,' ');

    int small=1000000000;
    for(int i=0;i<Oven.size();++i){
        if(Oven[i]<small)small=Oven[i];
        else Oven[i]=small; 
    }
    int lo,hi,mid;
    int lastpos=Oven.size();
    int pos=0;
    for(int i=0;i<Dows.size();++i){
        lo=0,hi=lastpos-1;pos=-1;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(Oven[mid]<Dows[i]) hi=mid-1;
            else if(Oven[mid]>Dows[i])lo=mid+1;
            else{
                pos=max(pos,mid);
                lo=mid+1;
            }
        }
        lastpos=max(pos,hi);
        if(lastpos==-1){
            cout<<0;
            return 0;
        }
    }
    cout<<lastpos+1;
}

/*
1.최대 계산수가 30만의 제곱이므로 완전 탐색은 x
2.주어진 오븐을 LDS로 바꾼다. 사이에 낀 다른 증감폭은 의미가 없기 때문.
3.이렇게 바꾼 후 각 도우의 위치를 이분 탐색으로 찾는다.(LDS이므로 정렬된 상태)
단 같은 값 중에서도 가장 밑에 있는 값을 찾아야 하므로 추가 처리 필요.
4.시뮬레이팅으로 필요없는 정보를 지워내면서 힌트를 얻는 문제.
이분 탐색 많이 연습해야겠다.
*/