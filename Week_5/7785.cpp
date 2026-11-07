#include <bits/stdc++.h>
using namespace std;

set<string, greater<string>> s; //set의 인자에 greater<type>을 넣어주면 내림차순으로 정렬해줌.
                                //기본값은 오름차순으로 정렬됨.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string name, state;
        cin >> name >> state;

        if(state == "enter") {
            s.insert(name);
        }
        else {
            auto it = s.find(name); //set은 중복을 허용하지 않기에
            if(it != s.end()) { //그냥 s.erase(name);이라고 해도 됨.
                s.erase(it); //multiset에서나 이런 식의 방어적 코드를 짜면 된다,.
            }
        }
    }

    for(auto n : s) {
        cout << n << '\n';
    }
}