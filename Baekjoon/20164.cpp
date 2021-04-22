#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

vector<int> Str2int(string n){
    vector<int> res;
    for(int i=0;i<n.size();++i){
        res.push_back(n[i]-'0');
    }
    return res;
}

void Calc(string n,int sum){
    vector<int> numbers=Str2int(n);
    if(n.size()==1){
        if(numbers[0]%2==1)answer.push_back(sum+1);
        else answer.push_back(sum);
    }else if(n.size()==2){
        if(numbers[0]%2==1)sum++;
        if(numbers[1]%2==1)sum++;
        Calc(to_string(numbers[0]+numbers[1]),sum);
    }else{
        for(int i=0;i<n.size();++i){
            if(numbers[i]%2==1)sum++;
        }
        for(int i=1;i<n.size()-1;++i){
            for(int j=i+1;j<n.size();++j){
                Calc(to_string(stoi(n.substr(0,i))+stoi(n.substr(i,j-i))+stoi(n.substr(j,n.size()-j))),sum);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string numb;
    cin>>numb;
    Calc(numb,0);
    cout<<*min_element(answer.begin(),answer.end())<<" "<<*max_element(answer.begin(),answer.end());
    return 0;
}
/*
1.재귀 사용해야하고, 문자열로 처리한다.
자릿수 제한때문에 왠만한 부하는 무시.
2.문자가 셋 이상일 경우 임의로 삼등분한다.
이때 각 문자가 시작하는 지점을 이중포문으로 구하면 모든 경우를 구할 수 있다. 첫 위치는 0 고정, 나머지는 1이상의 수.
*/