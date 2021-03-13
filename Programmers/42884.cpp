#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end());
    int target=0;
    int cam= routes[0][1];
    for(int i=0; i<routes.size(); ++i){
        if(routes[i][0]>cam){
            answer++;
            cam=routes[i][1];
        }
        else{
            if(cam>routes[i][1]){
                cam=routes[i][1];
            }
        }
    }
    answer++;
    return answer;
}

//https://programmers.co.kr/questions/14636