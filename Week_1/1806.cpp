#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, S;
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int min_len = 150000;
    int sum = 0;

    int l = 0;
    for(int r = 0; r < N; r++) {
        sum += arr[r];

        while(sum >= S) {
            min_len = min(min_len, r-l+1);

            sum -= arr[l];
            l++;
        }
    }

    if(min_len == 150000) cout << 0;
    else cout << min_len;
}