#include <bits/stdc++.h>
using namespace std;

list<int> l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        l.push_back(i);
    }

    cout << '<';

    int cnt = 0;
    auto it = l.begin();
    while(!l.empty()) {
        if(it == l.end()) { //원형 리스트: 항상 it를 조절하거나, erase등을 하기 전, 반복문의 제일 앞에서 end()인지를 체크해줘야함.
            it = l.begin();
        }

        cnt = (cnt + 1) % K;

        if(cnt == 0) {
            if(l.size() != 1) cout << *it << ", ";
            else cout << *it;

            it = l.erase(it); //★erase()는 원소를 삭제하고 다음원소를 리턴하기에 항상 it로 다시 받아줘야함.
        }
        else it++;
    }

    cout << '>';
}