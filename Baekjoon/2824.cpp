#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> split(string s, char del){
    vector<int> res;
    string temp;
    stringstream ss(s);
    while(getline(ss,temp,del)){
        res.push_back(stoi(temp));
    }
    return res;
}

int main(){
    int n,m;
    string temp;
    cin>>n;
    cin.ignore();
    getline(cin,temp);
    vector<int> N=split(temp,' ');
    cin>>m;
    cin.ignore();
    getline(cin,temp);
    vector<int> M=split(temp,' ');
    vector<int> tp;
    for(int i=0;i<n;++i){
        int num=N[i];
        while (num % 2 == 0) {
		num /= 2;
            tp.push_back(2);
        }
        for (int i = 3; i * i <= num; i += 2)
            while (num % i == 0) {
                num /= i;
                tp.push_back(i);
            }
        if (num != 1) tp.push_back(num);
    }
    N=tp;
    tp={};
    for(int i=0;i<n;++i){
        if(M[i]==1) continue;
        int k=2;
        while(M[i]>=k){
            if(M[i]%k==0){
                while(M[i]%k==0){
                    tp.push_back(k);
                    M[i]/=k;
                }
            }
            k++;
        }
    }
    M=tp;
    n=N.size(); 
    m=M.size();
    int i=0,j=0;
    long long res=1;
    sort(N.begin(),N.end());
    sort(M.begin(),M.end());
    while(i<n && j<m){
        //cout<<N[i]<<" "<<M[j]<<'\n';
        if(N[i]==M[j]){
            res*=N[i];
            i++;
            j++;
        }else{
            if(i==n-1 && j==m-1) break;
            else if(i==n-1)j++;
            else if(j==m-1)i++;
            else if(N[i]>M[j])j++;
            else i++;
        }
    }
    //cout<<res<<'\n';
    string ans=to_string(res);
    if(ans.size()>9)ans=ans.substr(ans.size()-9,9);
    cout<<ans;
}

/*
1. N,M을 소인수분해한다.
2. 소인수분해된 N,M을 정렬한 후 같은 수만 골라낸다.
포인터가 서로 같은 값을 뽑으면 정답에 곱하고,
아닐 경우 같은 수가 나올때까지 작은 수의 인덱스를 올린다.
3. 소인수분해의 경우 제곱까지 for문을 돌리면 된다.
인자 n에 대해 2 이상의 나머지가 0인 수 k를 잡아 더이상 안나눠질때까지 나눈다.
k의 배수로는 더이상 나눠지지 않으므로 이후 숫자에 대해서는 반드시 나머지가 생긴다.
이를 반복해 k가 n보다 커지면 멈춘다.
4. 시간이 초과되기 때문에 에라토스테네스의 채로 캐싱해둬야 한다.
*/

//https://github.com/Yukariko/acm/blob/master/problem/2824/test.c
//https://www.acmicpc.net/problem/2824