#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> adj[101];
vector<int> result;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cond; cin >> cond;
            if (cond == 1) {
                adj[i+1].push_back(j+1);
            }
        }
    }

    queue<int> q;
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 1; i <= N; i++) {
        vector<bool> visited(N+1, false);

        q.push(i);

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int n : adj[cur]) {
                if (!visited[n]) {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }

        for (int j = 0; j < N; j++) {
            if (visited[j+1]) {
                result[i-1][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}