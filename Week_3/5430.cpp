#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string str_arr;
        cin >> str_arr;

        deque<int> d;

        string temp = "";
        for(char c : str_arr) {
            if(isdigit(c)) {
                temp += c;
            }
            else {
                if(temp != "") {
                    d.push_back(stoi(temp)); //stoi: string to int
                    temp = "";
                }
            }
        }

        bool is_error = false;
        bool is_reversed = false;

        for(char cmd : p) {
            if(cmd == 'R') {
                is_reversed = !is_reversed; //반전
            } 
            else { // 'D'
                if(d.empty()) {
                    is_error = true;
                    break;
                }

                if (!is_reversed) { //정방향이면 front를 pop
                    d.pop_front();
                } 
                else { //역방향이면 back을 pop
                    d.pop_back();
                }
            }
        }

        if(is_error) {
            cout << "error\n";
            continue;
        }

        cout << '[';
        if(!d.empty()) {
            if(!is_reversed) { //정방향이면
                for(size_t i = 0; i < d.size(); i++) {
                    cout << d[i];
                    if(i + 1 < d.size()) cout << ',';
                }
            } 
            else { //역방향이면
                for(size_t i = 0; i < d.size(); i++) {
                    cout << d[d.size() - 1 - i];
                    if(i + 1 < d.size()) cout << ',';
                }
            }
        }
        cout << "]\n";
    }

    return 0;   
}