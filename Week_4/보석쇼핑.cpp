#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> gem_types(gems.begin(), gems.end());
    int total_types = gem_types.size();
    
    unordered_map<string, int> gem_counts;
    vector<int> answer = {1, (int)gems.size()}; //기본값은 처음부터 끝까지로
    
    int start = 0;
    int min_len = 100001; // 배열 최대 길이가 100,000
    for (int end = 0; end < (int)gems.size(); end++) {
        gem_counts[gems[end]]++;
        
        while (gem_counts.size() == total_types) {
            int current_len = end - start + 1;
            
            if (current_len < min_len) {
                min_len = current_len;
                answer[0] = start + 1; //진열대 번호는 1-indexed
                answer[1] = end + 1;
            }

            gem_counts[gems[start]]--;
            if (gem_counts[gems[start]] == 0) {
                gem_counts.erase(gems[start]); // 개수가 0이 되면 맵에서 완전히 삭제하여 size()가 줄어들게 함
            }
            start++;
        }
    }
    return answer;
}