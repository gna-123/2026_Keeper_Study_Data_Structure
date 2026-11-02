#include <bits/stdc++.h>
using namespace std;

//시간 복잡도: N은 phone_book의 길이로 최대 백만임.
//phone의 최대 길이(M)는 20임.
//O(N * M^2)은 최악의 경우 백만 * 20^2으로 4억회가 됨.
//하지만 발견 즉시 종료하는 조기 탈출(return false;)로 시간 내에 통과

bool solution(vector<string> phone_book) {
    unordered_set<string> u_s(phone_book.begin(), phone_book.end());
    for(auto phone : u_s) {
        string temp = "";
        for(int i = 0; i < phone.length() - 1; i++) { //내가 틀린 점: i를 0부터 끝까지로 해서 자기자신을 검사하면 항상 u_s에 phone이 있기에 false를 반환함.
            temp += phone[i];
            if(u_s.find(temp) != u_s.end()) {
                return false;
            }
        }
    }
    return true;
}