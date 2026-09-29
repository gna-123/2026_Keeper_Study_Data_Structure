#include <bits/stdc++.h>
using namespace std;

//사실 double linked list보다 deque를 쓰는게 훨씬 효율적임. list와 deque 둘다 O(1)에 원소 추가가 가능하지만, list는 포인터등 오버헤드가 꽤 있는 편.

list<int> past;
int skill[1000005]; //반대로 바닥(present) -> 내 손(past)으로 역으로 생각해야함.
                    //1번 기술은 제일 위로 보내야함.
                    //2번 기술은 두번째 위로 보내야함.
                    //3번 기술은 제일 밑으로 보내야함.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> skill[i];
    }

    for(int i = N; i >= 1; i--) {
        if(skill[i] == 1) {
            past.push_front(i);
        }
        else if(skill[i] == 2) {
            auto it = past.begin();
            it++;
            past.insert(it, i);
        }
        else { //skill[i] == 3
            past.push_back(i);
        }
    }
    
    for(auto e : past) {
        cout << e << ' ';
    }
}