#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;
    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n+1, -1);
    dist[b] = 0;
    queue<int> q;
    q.push(b);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == a) break;
        for (int next : adj[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[a];

    return 0;
}
