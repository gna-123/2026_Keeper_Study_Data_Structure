#include <bits/stdc++.h>
using namespace std;


bool cmp1(pair<string, int>& a, pair<string, int>& b) { // 난 그냥 auto a, auto b로 함.
    return a.second > b.second;
}

bool cmp2(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> tot;
    unordered_map<string, vector<pair<int, int>>> u_m;
    
    for(int i = 0; i < genres.size(); i++) {
        tot[genres[i]] += plays[i];
        u_m[genres[i]].push_back({plays[i], i});
    }

    vector<pair<string, int>> tot_v(tot.begin(), tot.end()); //★unordered_map은 sort()를 사용할 수 없으니 반드시 vector로 옮겨서 sort()를 수행하자.
    sort(tot_v.begin(), tot_v.end(), cmp1); //장르별 재생 횟수(내림차순)
    
    vector<int> answer;

    for(auto t : tot_v) {
        string genre = t.first;
        sort(u_m[genre].begin(), u_m[genre].end(), cmp2); //★똑같이 unordered_map은 sort() 사용 X
                                                          //u_m[genre]는 vector<pair<int, int>>
                                                          //해당 장르에서 곡별 재생 횟수(내림차순) -> 고유 번호(오름차순)

        for(int i = 0; i < u_m[genre].size() && i < 2; i++) {
            answer.push_back(u_m[genre][i].second);
        }
    }
    
    return answer;
}