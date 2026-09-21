#include <bits/stdc++.h>
using namespace std;

//N이 최대 1000이니 정렬에 드는 비용 O(NlogN)으로 1초 내에 충분히 통과 가능.

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    for(auto e : v) {
        cout << e << '\n';
    }
}