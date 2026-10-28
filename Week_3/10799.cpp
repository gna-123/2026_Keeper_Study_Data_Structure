#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int ans = 0;
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            s.push(str[i]);
        }
        else {
            if (str[i - 1] == '(') { //직전 문자가 '('라면 레이저
                s.pop();
                ans += s.size();
            } 
            else { //막대기의 끝
                s.pop();
                ans += 1;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}