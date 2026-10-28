#include <bits/stdc++.h>
using namespace std;

deque<int> d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while(N--) {
        string op;
        cin >> op;
        if(op == "push_front") {
            int x;
            cin >> x;
            d.push_front(x);
        }
        else if(op == "push_back") {
            int x;
            cin >> x;
            d.push_back(x);
        }
        else if(op == "pop_front") {
            if(!d.empty()) {
                cout << d.front() << '\n';
                d.pop_front();
            }
            else cout << -1 << '\n';
        }
        else if(op == "pop_back") {
            if(!d.empty()) {
                cout << d.back() << '\n';
                d.pop_back();
            }
            else cout << -1 << '\n';
        }
        else if(op == "size") {
            cout << d.size() << '\n';
        }
        else if(op == "empty") {
            if(d.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(op == "front") {
            if(!d.empty()) {
                cout << d.front() << '\n';
            }
            else cout << -1 << '\n';
        }
        else { //op == "back"
            if(!d.empty()) {
                cout << d.back() << '\n';
            }
            else cout << -1 << '\n';
        }
    }
}