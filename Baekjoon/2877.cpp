#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n,cnt=0;
    string res;
    cin>>n;
    for(int i=1;i<50;++i){
        if(n-pow(2,i)>0) cnt++;
        else break;
        n-=pow(2,i);
    }
    int i=0;
    cnt++; n--;
    for(int flag=1;i<cnt;flag=flag<<1){
        if((flag&n)==0) res='4'+res;
        else res='7'+res;
        i++;
    }
    cout<<res;
}