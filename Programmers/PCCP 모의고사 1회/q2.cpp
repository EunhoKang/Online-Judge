#include <string>
#include <vector>

using namespace std;

int result = 0;
int taken[10];
vector<vector<int>> Ability;

void getMax(int cnt, int sum)
{
    if(cnt == Ability[0].size()) result = max(result, sum);
    else
    {
        for(int i = 0; i < Ability.size(); ++i)
        {
            if(taken[i] == 1) continue;
            taken[i] = 1;
            getMax(cnt + 1, sum + Ability[i][cnt]);
            taken[i] = 0;
        }
    }
}

int solution(vector<vector<int>> ability) {
    int answer = 0;
    int sum = 0;
    Ability = ability;
    getMax(0,0);
    answer = result;
    return answer;
}

/*
*/