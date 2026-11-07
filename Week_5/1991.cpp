#include <bits/stdc++.h>
using namespace std;

int lc[30];
int rc[30];

void preorder(int cur) {
    if(cur == -1) return;
    cout << (char)(cur + 'A');
    preorder(lc[cur]);
    preorder(rc[cur]);
}

void inorder(int cur) {
    if(cur == -1) return;
    inorder(lc[cur]);
    cout << (char)(cur + 'A');
    inorder(rc[cur]);
}

void postorder(int cur) {
    if(cur == -1) return;
    postorder(lc[cur]);
    postorder(rc[cur]);
    cout << (char)(cur + 'A');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(lc, lc + 30, -1);
    fill(rc, rc + 30, -1);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int cur, left, right;
        cin >> cur >> left >> right;

        if(left != '.') lc[cur - 'A'] = left - 'A';
        if(right != '.') rc[cur - 'A'] = right - 'A';
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);

    return 0;
}