#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int pelindrom(string s, int skip){
    int left=0,right=s.size()-1;
    while(left<=right){
        if(s[left]!=s[right]){
            if(skip<=0) return 2;
            return min(pelindrom(s.substr(left+1,right-left),0),pelindrom(s.substr(left,right-left),0));
        }
        left++;right--;
    }
    if(skip==0) return 1;
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<string> strs;
    for(int i=0;i<n;++i){
        string t;
        cin>>t;
        strs.push_back(t);
    }
    for(int i=0;i<n;++i){
        cout<<pelindrom(strs[i],1)<<'\n';
    }
}

/*
앞에서부터 순서대로 체크하고 펠린드롬이 깨지는 루틴이 발견되면 문자를 건너뛴다.
이때 좌우 분기가 나뉘는데 함수를 재활용해서 둘다 확인해야 한다.
*/