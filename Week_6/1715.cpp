#include <bits/stdc++.h>
using namespace std;

//총 N번 pop, push를 진행하고, pop, push는 전부 O(logN)이므로 O(NlogN)이 필요함.
//N의 최대값이 100000이기에 2초 내에 충분히 통과한다.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int N;
    cin >> N;
    for(int i = 0 ; i < N; i++) {
        int n;
        cin >> n;
        pq.push(n);
    }
    long long tot = 0; //모든 묶음이 1000으로 N이 100000개라면, int의 범위를 훨씬 초과하기에 long long으로
    for(int i = 0; i < N-1; i++) { //N이 만약에 1이라면 비교를 한 번도 진행하지 않기에 0을 출력해야하니깐 
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        pq.push(a+b);
        tot += a+b;
    }
    cout << tot; 
}