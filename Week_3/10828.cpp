#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while(N--) {
        string op;
        cin >> op;
        if(op == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if(op == "pop") {
            if(!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
            else cout << -1 << '\n';
        }
        else if(op == "size") {
            cout << s.size() << '\n';
        }
        else if(op == "empty") {
            if(s.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else { //op == "top"
            if(!s.empty()) {
                cout << s.top() << '\n';
            }
            else cout << -1 << '\n';
        }
    }
}