#include <string>
#include <iostream>
#include <vector>

using namespace std;

int First(int n){
    return n%5+1;
}
int Second(int n){
    if(n%2==0) return 2;
    else if(n%8==1) return 1;
    else if(n%8==3) return 3;
    else if(n%8==5) return 4;
    else if(n%8==7) return 5;
    return -1;
}
int Third(int n){
    if((n/2)%5==0) return 3;
    else if((n/2)%5==1) return 1;
    else if((n/2)%5==2) return 2;
    else if((n/2)%5==3) return 4;
    else if((n/2)%5==4) return 5;
    return -1;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt[3]={0,};
    for(int i=0;i<answers.size();++i){
        if(First(i)==answers[i]) cnt[0]++;
        if(Second(i)==answers[i]) cnt[1]++;
        if(Third(i)==answers[i]) cnt[2]++;
    }
    int res=0;
    for(int i=0;i<3;++i){
        res=res>cnt[i]?res:cnt[i];
        cout<<res<<" "<<cnt[i]<<'\n';
    }
    for(int i=0;i<3;++i){
        if(cnt[i]==res) answer.push_back(i+1);
    }
    return answer;
}

int main(){
    vector<int> s=solution({1, 3, 2, 4, 2});
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
}