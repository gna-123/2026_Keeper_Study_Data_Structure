#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> u_m;
    for(auto cloth : clothes) {
        u_m[cloth[1]]++;
    }
    for(auto cloth : u_m) { //cloth의 타입은 pair<string, int>
        answer *= (cloth.second + 1);
    }
    return answer - 1;
}