#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        list<char> l;

        string s;
        cin >> s;

        auto it = l.begin();

        for(auto c : s) {
            if(c == '>') {
                if(it == l.end()) continue;
                
                it++;
            }
            else if(c == '<') {
                if(it == l.begin()) continue;

                it--;
            }
            else if(c == '-') {
                if(it == l.begin()) continue;

                it--;
                it = l.erase(it);
            }
            else { //대, 소문자 //여기서 push_back 대신 insert를 써야함.
                l.insert(it, c);
            }
        }
        for(auto c : l) {
            cout << c;
        }
        cout << '\n';
    }
}