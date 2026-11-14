#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //first는 절대값, second는 0(음수), 1(양수)
                                                                                        //★first에 절대값, second에는 원본값을 넣으면 훨씬 좋음.

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if(x == 0) {
            if(!pq.empty()) {
                auto [value, sign] = pq.top(); //★cout << pq.top().second << '\n';로 3줄 전체 대체 가능.
                                               //★first가 같으면 자동으로 second를 오름차순으로 정렬하기에 -5와 5가 있으면 -5를 먼저 꺼내니깐.
                if(sign == 1) cout << value << '\n';
                else cout << -value << '\n';
                pq.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            if(x < 0) { //★pq.push({abs(x), x});로 대체 가능
                pq.push({-x, 0});
            }
            else {
                pq.push({x, 1});
            }
        }
    }
}