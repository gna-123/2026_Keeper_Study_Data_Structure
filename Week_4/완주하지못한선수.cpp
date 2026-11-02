#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> u_m;
    for(auto p : participant) {
        u_m[p]++; //p라는 키가 없으면 {p:0}으로 원소 추가
                  //p라는 키가 이미 있으면 값을 +1 해줌.
    }
    for(auto c : completion) {
        u_m[c]--;
    }

    for(auto ans : u_m) {
        if(ans.second > 0) return ans.first;
    }
}

/* //unordered_multiset을 이용한 코드
string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> u_ms(participant.begin(), paticipant.end()); //unordered_multiset은 unordered_set과 달리 중복을 허용해줌.

    for(auto name : completion) {
        auto it = u_ms.find(name); //★하지만 만약 그냥 u_ms.erase(name);이라고 하면 name이라는 모든 원소가 삭제됨.
        if(it != u_ms.end()) { //★그래서 반드시 u_ms.find(name)으로 이터레이터를 받고, u_ms.erase(이터레이터);를 해야 하나의 원소만 삭제됨.
            u_ms.erase(it);
        }
    }

    return *u_ms.begin();
}
*/