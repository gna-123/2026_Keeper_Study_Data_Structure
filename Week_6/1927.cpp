#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if(x == 0) {
            if(!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            pq.push(x);
        }
    }
}