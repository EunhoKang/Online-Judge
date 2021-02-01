#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> get;
    vector<int> give;
    answer=n-lost.size();
    for(int i=0;i<lost.size();++i) get.push_back(0);
    for(int i=0;i<reserve.size();++i) give.push_back(0);
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    for(int i=0;i<reserve.size();++i){
        if(!give[i]){
            for(int j=0;j<lost.size();++j){
                if(!get[j]){
                    if(reserve[i]==lost[j]){
                        get[j]=1;
                        give[i]=1;
                        answer++;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<reserve.size();++i){
        if(!give[i]){
            for(int j=0;j<lost.size();++j){
                if(!get[j]){
                    if(reserve[i]-1==lost[j] || reserve[i]+1==lost[j]){
                        get[j]=1;
                        answer++;
                        break;
                    }
                }
            }
        }
    }
    return answer;
}

/*
문제 조건이 복잡하네...
*/