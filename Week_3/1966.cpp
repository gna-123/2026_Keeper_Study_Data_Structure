#include <bits/stdc++.h>
using namespace std;

//최악의 경우, 하나의 테스트케이스마다 N이 최대 100, 우선순위가 전부 같으면 처음부터 끝까지 비교(O(N))를 제일 마지막에 출력되는 target까지(O(N)) 수행하면 O(N^2) = 10000이 필요.
//테스트케이스가 2*10^5이하면 2*10^5 * 10000 == 2*10^9으로 2초 내에 통과 가능

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        deque<pair<int, int>> d; //{index, priority}
        int N;
        cin >> N;

        int target;
        cin >> target;

        for(int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            d.push_back({i, priority});
        }

        if(N == 1) {
            cout << 1 << '\n';
            continue;
        }

        int cnt = 0;
        while(!d.empty()) {
            auto cur = d.front();
            d.pop_front();

            bool most_important = true; //cur가 덱에 있는 모든 원소 중 가장 우선순위가 높은 원소면 true
            for(int i = 0; i < d.size(); i++) { //최대힙과 d를 같이 사용하면 해당 for문을 없애도 됨.
                if(d[i].second > cur.second) {
                    most_important = false;
                    break;
                }
            }
            if(most_important) { //most_important == true
                cnt++;
                if(cur.first == target) {
                    cout << cnt << '\n';
                    break;
                }
            }
            else { //most_important == false
                d.push_back(cur);
            }
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int N, target;
        cin >> N >> target;

        deque<pair<int, int>> d; //index, priority}
        priority_queue<int> pq; //최대힙(우선순위 큐)    
                                //중요도를 내림차순으로 O(1)에 자동 정렬

        for(int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            d.push_back({i, priority});
            pq.push(priority);
        }

        int cnt = 0;
        while(!d.empty()) {
            auto cur = d.front();
            d.pop_front();

            if(cur.second == pq.top()) { //만약 cur의 우선순위가 덱에 있는 최우선순위와 같다면
                                         //최대힙, 최소힙은 각각 최대값, 최솟값을 O(1)에 반환해줌.
                pq.pop();
                cnt++;

                if(cur.first == target) {
                    cout << cnt << '\n';
                    break;
                }
            }
            else {
                d.push_back(cur);
            }
        }
    }
    return 0;
}
*/