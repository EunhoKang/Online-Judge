#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,pair<priority_queue<pair<int,int>>,int>> m;
    for(int i=0;i<genres.size();++i){
        if(m.find(genres[i])==m.end()){
            priority_queue<pair<int,int>> tp;
            tp.push(make_pair(plays[i],-1*i));
            m.insert(make_pair(genres[i], make_pair(tp,plays[i])));
        }else{
            m[genres[i]].first.push(make_pair(plays[i],-1*i));
            m[genres[i]].second+=plays[i];
        }
    }
    int res=0;
    priority_queue<pair<int,string>> Q;
    unordered_map<string,pair<priority_queue<pair<int,int>>,int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        Q.push(make_pair(it->second.second,it->first));
    }
    while (!Q.empty()) {
        pair<priority_queue<pair<int,int>>,int> temp=m[Q.top().second];
        if(temp.first.size()==1){
            answer.push_back(temp.first.top().second*-1);
            cout<<temp.first.top().second*-1<<'\n';
        }else{
            answer.push_back(temp.first.top().second*-1);
            cout<<temp.first.top().second*-1;
            temp.first.pop();
            answer.push_back(temp.first.top().second*-1);
            cout<<temp.first.top().second*-1<<'\n';
        }
        Q.pop();
    }
    
    return answer;
}

int main(){
    solution({"classic", "pop", "classic", "dd", "pop"},{500, 600, 150, 800, 2500,300});
    return 0;
}

/*
1.이...이게 대체....
*/