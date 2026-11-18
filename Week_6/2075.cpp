#include <bits/stdc++.h>
using namespace std;

//메모리 제한이 12MB로 매우 매우 작음.
//그래서 입력받는 즉시 처리해야함.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;

    int N;
    cin >> N;
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < N; i++) {
            int n;
            cin >> n;
            pq.push(n);
            if(pq.size() > N) {
                pq.pop();
            }
        }
    }
    cout << pq.top();

}