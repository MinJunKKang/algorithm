#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<int> adj[N];
    vector<vector<char>> mat(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
            if (j > i && mat[i][j] == 'Y') {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int ans = 0;
    vector<int> dist(N);
    queue<int> q;

    for (int i = 0; i < N; i++) {
        dist.assign(N, -1);
        dist[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (dist[v] == 2) continue;

            for (auto u: adj[v]) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }

        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (dist[j] >= 1 && dist[j] <= 2) cnt++;
            ans = max(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}