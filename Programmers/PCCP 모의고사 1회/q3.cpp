#include <string>
#include <vector>

using namespace std;

string getPea(int generation, int cnt)
{
    if(generation == 1) return "Rr";
    else
    {
        string parent = getPea(generation - 1, cnt / 4);
        if(parent == "RR") return "RR";
        else if(parent == "rr") return "rr";
        else
        {
            if(cnt % 4 == 0) return "RR";
            else if(cnt % 4 == 3) return "rr";
            else return "Rr";
        }
    }
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for(auto query : queries)
    {
        answer.push_back(getPea(query[0], query[1]-1));
    }
    return answer;
}

/*
1.
*/