/*
#include <bits/stdc++.h>
using namespace std;

//list를 사용했음. 논리적으론 맞지만 TLE가 발생.
//std::find()는 O(N)이 걸림.
//N은 최대 50만, M은 150만임.
//그러면 최악의 경우, O(N*M)만큼 걸림. NM = 7조 5000억번. 2초안에 절대 불가.

//그러면 어떻게 해결해야할까? -> 야매 연결리스트를 사용해야함. 야매 연결리스트는 배열 pre, nxt를 이용하여 경로 추적에 주로 쓰임.
//배열을 사용하기에 인덱스로 접근가능하여 O(1)에 바로 노드 한 칸 이동이 가능.


list<int> l;

auto it = l.begin();

auto find_i_idx(int i) {
    return find(l.begin(), l.end(), i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        l.push_back(n);
    }

    for(int i = 0; i < M; i++) {
        string op;
        cin >> op;
        if(op == "BN") { //i+1출력, i j i+1
            int i, j;
            cin >> i >> j;

            it = find_i_idx(i);

            it++;
            if(it == l.end()) it = l.begin();

            cout << *it << '\n';

            l.insert(it, j);

        }
        else if(op == "BP") { //i-1출력, i-1 j i
            int i, j;
            cin >> i >> j;

            it = find_i_idx(i);

            if(it == l.begin()) it = l.end();
            it--;

            cout << *it << '\n';

            l.insert(++it, j);
        }
        else if(op == "CN") { //i+1출력, 삭제
            int i;
            cin >> i;

            it = find_i_idx(i);

            it++;
            if(it == l.end()) it = l.begin();

            cout << *it << '\n';

            it = l.erase(it);
        }
        else { //op == "CP" //i-1출력, 삭제
            int i;
            cin >> i;

            it = find_i_idx(i);

            if(it == l.begin()) it = l.end();
            it--;

            cout << *it << '\n';

            it = l.erase(it);
        }
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

// 역 번호가 최대 1,000,000이므로 크기를 1,000,005로 잡음
int nxt[1000005];
int prv[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    int first_station = -1;
    int prev_station = -1;
    
    // 1. 초기 원형 연결 리스트 구성
    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if(i == 0) {
            first_station = n;
        } else {
            nxt[prev_station] = n;
            prv[n] = prev_station;
        }
        prev_station = n;
    }
    // 처음과 끝을 연결하여 원형으로 만듦
    nxt[prev_station] = first_station;
    prv[first_station] = prev_station;

    // 2. M개의 쿼리 처리 (모두 O(1)에 동작)
    for(int i = 0; i < M; i++) {
        string op;
        cin >> op;
        
        if(op == "BN") {
            int i_val, j_val;
            cin >> i_val >> j_val;
            
            int next_val = nxt[i_val];
            cout << next_val << '\n';
            
            // i_val과 next_val 사이에 j_val 삽입
            nxt[i_val] = j_val;
            prv[j_val] = i_val;
            
            nxt[j_val] = next_val;
            prv[next_val] = j_val;
            
        } 
        else if(op == "BP") {
            int i_val, j_val;
            cin >> i_val >> j_val;
            
            int prev_val = prv[i_val];
            cout << prev_val << '\n';
            
            // prev_val과 i_val 사이에 j_val 삽입
            nxt[prev_val] = j_val;
            prv[j_val] = prev_val;
            
            nxt[j_val] = i_val;
            prv[i_val] = j_val;
        } 
        else if(op == "CN") {
            int i_val;
            cin >> i_val;
            
            int next_val = nxt[i_val];
            cout << next_val << '\n';
            
            // next_val을 삭제 (i_val과 next_val의 다음 역을 다이렉트로 연결)
            int next_next_val = nxt[next_val];
            nxt[i_val] = next_next_val;
            prv[next_next_val] = i_val;
        } 
        else if(op == "CP") {
            int i_val;
            cin >> i_val;
            
            int prev_val = prv[i_val];
            cout << prev_val << '\n';
            
            // prev_val을 삭제 (prev_val의 이전 역과 i_val을 다이렉트로 연결)
            int prev_prev_val = prv[prev_val];
            nxt[prev_prev_val] = i_val;
            prv[i_val] = prev_prev_val;
        }
    }
}