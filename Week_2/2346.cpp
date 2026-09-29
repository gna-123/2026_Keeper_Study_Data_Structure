#include <bits/stdc++.h>
using namespace std;

list<int> l;
int jump[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        l.push_back(i);
        cin >> jump[i];
    }

    auto it = l.begin();
    while(!l.empty()) {
        if(it == l.end()) it = l.begin(); //원형 리스트 적용
        
        cout << *it << ' ';
        int jump_dist = jump[*it];

        it = l.erase(it); //★ 1. it가 무효화되지 않도록 반드시 erase 후에 it 받아주기.
                          //★ 또한 erase()를 하면 it가 다음 원소를 가리키게 됨.

        if(l.empty()) break; //★★ 2. 항상 erase()를 한 뒤에 컨테이너가 비었는지 체크를 해야함. 비었을때 it는 begin()을 가리키는데 거기서 ++, --를 하면 XXX

        //★★
        if(jump_dist < 0) { //★★내가 헷갈린 부분. 예를 들어 1, 2, 3, 4, 5에서 jump[1] = -3임. 1이 erase되었으니 it는 2를 가리킴. 2는 현재 begin()임.
            jump_dist *= -1; //jump_dist에는 3이 저장.

            while(jump_dist--) {
                if(it == l.begin()) it = l.end(); //2를 가리키던 it는 begin()이니 end()로 이동.
                it--; //end()에서 --를 하면 it가 5를 가리킴. end()가 5를 가리키는게 아니니깐.
            }
        }
        //★★

        else { //jump_dist > 0
            jump_dist -= 1; //이미 erase로 it++를 한번 했음.

            while(jump_dist--) {
                it++;
                if(it == l.end()) it = l.begin();
            }
        }
    }
}