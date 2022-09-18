#include <string>
#include <vector>

using namespace std;

int zero = 0;
int epoch = 0;

string compact(string s)
{
    int cnt = 0;
    for(auto a : s) if(a == '1') cnt++;
    zero += s.length() - cnt;
    epoch += 1;
    string newstr = "";
    while(cnt > 0)
    {
        if(cnt % 2 == 1) 
        {
            newstr = "1" + newstr;
            cnt--;
        }
        else newstr = "0" + newstr;
        cnt /= 2;
    }
    return newstr;
}

vector<int> solution(string s) {
    vector<int> answer;
    string str = s;
    while(str != "1") str = compact(str);
    answer = {epoch, zero};
    return answer;
}