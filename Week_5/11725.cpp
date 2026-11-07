#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int par[100005];
bool vis[100005]; //vis 배열을 굳이 안써도 됨.
                  //par[cur] == 0이라면 미방문한 노드이기 때문에

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = true; //par[1] = -1; //0이 미방문을 의미.

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]) {
            if(vis[nxt]) continue; //if(par[nxt] != 0) continue;

            q.push(nxt);
            vis[nxt] = true; //이 코드는 삭제해도 됨.
            par[nxt] = cur;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 1; i < N; i++) { //트리에 N개의 노드가 있다면 간선은 N-1개가 존재
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }

    bfs();

    for(int i = 2; i <= N; i++) {
        cout << par[i] << '\n';
    }
}