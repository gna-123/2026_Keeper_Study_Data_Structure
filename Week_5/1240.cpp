#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[1005]; //맞은 편 노드, 해당 간선 가중치

int bfs(int start, int end) { //트리니깐 두 정점 사이에는 유일한 경로가 존재함.
                              //그래서 평범한 그래프 문제와는 다르게 최소 경로인지 계속 확인할 필요 없음.
                              //노드가 최대 천 개, bfs를 최대 천 번 돌려야하니깐 1000 * O(V + E) == 10^3 * 2000이므로 최악의 경우라도 2초 내에 실행 가능.
    int dist[1005];
    fill(dist, dist + 1005, -1);
    
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        if(cur == end) return dist[cur];
        q.pop();

        for(auto nxt : adj[cur]) { //for(auto [nxt, cost] : adj[cur])로 first, second를 사용하는 것보다 실수가 적어짐.
            if(dist[nxt.first] != -1) continue;

            q.push(nxt.first);
            dist[nxt.first] = dist[cur] + nxt.second;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 1; i < N; i++) {
        int s, t, dist;
        cin >> s >> t >> dist;

        adj[s].push_back({t, dist});
        adj[t].push_back({s, dist});
    }

    while(M--) {
        int st, en;
        cin >> st >> en;
        cout << bfs(st, en) << '\n';
    }
}