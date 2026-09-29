#include <bits/stdc++.h>
using namespace std;

list<char> l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for(auto c : s) {
        l.push_back(c);
    }

    auto it = l.end();

    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        char op;
        cin >> op;
        
        if(op == 'L') {
            if(it == l.begin()) continue;
            else it--;
        }
        else if(op == 'D') {
            if(it == l.end()) continue;
            else it++;
        }
        else if(op == 'B') {
            if(it == l.begin()) continue;
            else {
                it--;
                it = l.erase(it); //erase하면 한칸 뒤로 이동하는거 생각 + it로 다시 받아주기
            }
        }
        else { //op == 'P'
            char c;
            cin >> c;
            l.insert(it, c); //여기가 그나마 헷갈리는 부분.
                             //a|b에서 사이에 c를 추가하면(현재 it는 b를 가리키는 중)
                             //ac|b가 됨. insert를 해도 it는 b를 꽉 붙잡고 있음. 그래서 추가적인 it 작업 안해도 됨.
        }
    }
    for(auto c : l) {
        cout << c;
    }
}