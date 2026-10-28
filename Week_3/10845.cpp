#include <bits/stdc++.h>
using namespace std;

queue<int> q;

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
            q.push(x);
        }
        else if(op == "pop") {
            if(!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << -1 << '\n';
        }
        else if(op == "size") {
            cout << q.size() << '\n';
        }
        else if(op == "empty") {
            if(q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(op == "front") {
            if(!q.empty()) {
                cout << q.front() << '\n';
            }
            else cout << -1 << '\n';
        }
        else { //op == "back"
            if(!q.empty()) {
                cout << q.back() << '\n';
            }
            else cout << -1 << '\n';
        }
    }
}