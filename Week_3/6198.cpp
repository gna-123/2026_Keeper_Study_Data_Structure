#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;
    
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;

        while (!s.empty() && s.top() <= height) {
            s.pop();
        }
        ans += s.size();

        s.push(height);
    }
    cout << ans << "\n";
    
    return 0;
}