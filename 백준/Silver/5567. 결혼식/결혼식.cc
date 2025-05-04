#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> adj(n+1);
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    vector<int> dist(n+1, -1);
    dist[1] = 0;
    q.push(1);

    int result = 0;
    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        if (dist[pos] >= 2) continue;

        for (int i: adj[pos]) {
            if (dist[i] == -1) {
                dist[i] = dist[pos] + 1;
                q.push(i);
                result++;
            }
        }
    }

    cout << result;
    return 0;
}
