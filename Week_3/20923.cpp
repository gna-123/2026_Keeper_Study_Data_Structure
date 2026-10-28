#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    deque<int> dodo_deck, su_deck; //deck: front가 덱의 맨 위(카드를 내는 곳), back이 덱의 맨 아래(카드를 넣는 곳)
    deque<int> dodo_ground, su_ground; //ground: front가 그라운드의 맨 위(보이는 카드), back이 그라운드의 맨 아래(바닥)

    for (int i = 0; i < N; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        dodo_deck.push_front(c1);
        su_deck.push_front(c2);
    }

    for (int turn = 0; turn < M; turn++) {
        if (turn % 2 == 0) { //도도 턴
            dodo_ground.push_front(dodo_deck.front());
            dodo_deck.pop_front();
            if (dodo_deck.empty()) { //수연 승리, 즉시 게임 종료
                cout << "su\n";
                return 0;
            }
        } 
        else { //수연 턴
            su_ground.push_front(su_deck.front());
            su_deck.pop_front();
            if (su_deck.empty()) { //도도 승리, 즉시 게임 종료
                cout << "do\n";
                return 0;
            }
        }

        int bell = 0; //1: 도도, 2: 수연
        if ((!dodo_ground.empty() && dodo_ground.front() == 5) || (!su_ground.empty() && su_ground.front() == 5)) {
            bell = 1; //도도 종 치는 조건: 어느 한 쪽이라도 그라운드 맨 위(front)가 5
        }
        else if (!dodo_ground.empty() && !su_ground.empty() && (dodo_ground.front() + su_ground.front() == 5)) {
            bell = 2; //수연 종 치는 조건: 양쪽 그라운드가 비어있지 않고, 맨 위(front)의 합이 5
        }

        if (bell == 1) { //도도가 종을 쳤으면
            while (!su_ground.empty()) { //수연 그라운드 흡수
                dodo_deck.push_back(su_ground.back());
                su_ground.pop_back();
            }
            while (!dodo_ground.empty()) { //도도 그라운드 흡수
                dodo_deck.push_back(dodo_ground.back());
                dodo_ground.pop_back();
            }
        } 
        else if (bell == 2) { //수연이 종을 쳤으면
            while (!dodo_ground.empty()) { //도도 그라운드 흡수
                su_deck.push_back(dodo_ground.back());
                dodo_ground.pop_back();
            }
            while (!su_ground.empty()) { //수연 그라운드 흡수
                su_deck.push_back(su_ground.back());
                su_ground.pop_back();
            }
        }
    }

    if (dodo_deck.size() > su_deck.size()) { //도도 승리
        cout << "do\n";
    } 
    else if (dodo_deck.size() < su_deck.size()) { //수연 승리
        cout << "su\n";
    } 
    else { //dodo_deck.size() == su_deck.size() //무승부
        cout << "dosu\n";
    }

    return 0;
}