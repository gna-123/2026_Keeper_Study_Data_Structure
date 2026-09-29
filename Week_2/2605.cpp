#include <bits/stdc++.h>
using namespace std;

list<int> l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) { //i번째 학생은 0 ~ i-1의 카드를 뽑을 수 있음.
                                  //해당 카드번호만큼 앞으로 이동해야함.
        int mv;
        cin >> mv;

        auto it = l.end();

        while(mv--) {
            it--;
        }

        l.insert(it, i);
    }

    for(auto e : l) {
        cout << e << ' ';
    }
}