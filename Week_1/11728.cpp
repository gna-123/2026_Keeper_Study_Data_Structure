#include <bits/stdc++.h>
using namespace std;

//A와 B를 합친 다음에 sort()를 하면 O((N+M)*log(N+M))이 필요함. N, M이 각각 백만이면 4200만이니 1.5초 내에 충분히 통과 가능.
//하지만 그렇게하면 A와 B가 이미 정렬된 상태라는 걸 충분히 사용하지 못함.
//그래서 투 포인터를 사용.
//투 포인터를 사용하면 O(N+M)이 필요함. 그래서 200만으로 20배 줄어들 수 있음.

vector<int> v_A;
vector<int> v_B;
vector<int> v_C;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) { //이미 정렬되어있음.
        int n;
        cin >> n;
        v_A.push_back(n);
    }
    for(int i = 0; i < M; i++) { //이미 정렬되어있음.
        int m;
        cin >> m;
        v_B.push_back(m);
    }

    //투 포인터 풀이.
    int a = 0;
    int b = 0;
    
    while(a < N && b < M) {
        if(v_A[a] <= v_B[b]) {
            v_C.push_back(v_A[a++]);
        }
        else {
            v_C.push_back(v_B[b++]);
        }
    }

    while(a < N) { //B가 먼저 끝났으면 남은 A 전체를 C에 붙이기
        v_C.push_back(v_A[a++]);
    }
    while(b < M) { //A가 먼저 끝났으면 남은 B 전체를 C에 붙이기
        v_C.push_back(v_B[b++]);
    }

    for(auto e : v_C) {
        cout << e << ' ';
    }

}