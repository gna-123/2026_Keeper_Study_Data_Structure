#include <bits/stdc++.h>
using namespace std;

int arr[100005]; 

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for(int i = 0 ; i < N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    int l = 0;
    int max_len = 0;

    for(int r = 0; r < N; r++) {
        arr[v[r]]++;

        while(arr[v[r]] > K) {
            arr[v[l]]--;
            l++;
        }

        max_len = max(max_len, r-l+1);
    }

    cout << max_len;
}