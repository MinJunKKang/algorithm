#include <iostream>
#include <vector>

using namespace std;
#define INF 1e9

int N;
vector<vector<int>> W;
vector<bool> visited;
int min_dist = INF;

void dfs(int pos, int dist, int cnt) {
    if (cnt == N-1) {
        if (W[pos][0] == 0) return;

        dist = dist + W[pos][0];
        min_dist = min(min_dist, dist);
        return;
    }

    for (int i = 1; i < N; i++) {
        if (visited[i] || W[pos][i] == 0) continue;

        visited[i] = true;
        dfs(i, dist + W[pos][i], cnt + 1);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    W.resize(N, vector<int>(N));
    visited.assign(N, false);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> W[i][j];
    }

    visited[0] = true;
    dfs(0, 0, 0);

    cout << min_dist;

    return 0;
}