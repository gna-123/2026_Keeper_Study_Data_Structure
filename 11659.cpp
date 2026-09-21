#include <bits/stdc++.h>
using namespace std;

//N이 십만, M이 십만임. 그냥 for문으로 합을 구하면 최악의 경우 O(N*M) = 100억으로 무조건 시간초과(TLE) 발생.
//i부터 j까지의 합을 구할때 가장 시간복잡도를 줄이기 쉬운건 prefix sum임.
//prefix sum은 dynamic programming으로 S(1부터 j까지의 합) - S(1부터 i-1까지의 합) = S(i부터 j까지의 합)임.

int arr[100005];
int dp[100005]; //dp[i]: 1부터 i까지의 합
                //최대 십만개가 전부 1000이어서 다 더해도 1억이므로 int 사용 가능.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = dp[i-1] + arr[i]; //DP 사용.
    }

    while(M--) {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << '\n'; //Prefix Sum 사용.
    }
}