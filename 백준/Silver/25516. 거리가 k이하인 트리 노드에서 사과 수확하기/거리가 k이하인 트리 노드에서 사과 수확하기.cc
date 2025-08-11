#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> apple(n);

    for (int i = 0; i < n-1; i++) {
        int p, c; cin >> p >> c;
        adj[p].push_back(c);
    }

    for (int i = 0; i < n; i++) {
        cin >> apple[i];
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto i: adj[cur]) {
            if (dist[i] != -1) continue;

            dist[i] = dist[cur] + 1;
            q.push(i);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] <= k) {
            if (apple[i] == 1) result++;
        }
    }

    cout << result;

    return 0;
}