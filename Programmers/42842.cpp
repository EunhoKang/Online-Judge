#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w,h;
    for(int h=3;h<=(brown+yellow)/3;++h){
        if((brown+yellow)%h==0){
            w=(brown+yellow)/h;
            if((w-2)*(h-2)==yellow){
                answer={w,h};
                break;
            }
        }
    }
    return answer;
}

int main(){
    vector<int> s=solution(24,24);
    cout<<s[0]<<","<<s[1];
}

/*
1.
w*h=brown+yellow
(w-2)*(h-2)=yellow
*/