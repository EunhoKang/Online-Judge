#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    int res=0;
    vector<pair<string,int>> tp;
    for(int i=0; i<numbers.size();++i){
        pair<string,int> temp=make_pair(to_string(numbers[i]),0);
        temp.second=temp.first.size();
        if(temp.first.size()<8) 
            while(temp.first.size()<8) 
                temp.first+=temp.first;
        tp.push_back(temp);
    }
    sort(tp.begin(),tp.end(),greater<pair<string,int>>());
    for(int i=0; i<numbers.size();++i){
        answer+=tp[i].first.substr(0,tp[i].second);
    }
    while(answer[0]=='0') answer=answer.substr(1);
    if(answer=="") answer="0";
    return answer;
}

/*
1.특정 문자열을 반복했을 때 기준으로 정렬해야 한다.
반복된 문자열끼리 비교해야 문자열 길이에 의한 정렬 오류를 잡을 수 있다.
2.0이 있을 경우 숫자로 변환 후 다시 문자열로 변환해야 함을 기억하자.
3.모범 답안은 정렬 함수를 커스텀하는 것. 아래와 같다.
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const string &a, const string &b)
{
    if (b + a < a + b)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> strings;

    for (int i : numbers)
        strings.push_back(to_string(i));

    sort(strings.begin(), strings.end(), compare);

    for (auto iter = strings.begin(); iter < strings.end(); ++iter)
        answer += *iter;

    if (answer[0] == '0')
        answer = "0";

    return answer;
}
*/