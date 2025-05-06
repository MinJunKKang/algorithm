#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int r1, c1, r2, c2;

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    vector<vector<int>> dist(N, vector<int>(N, -1));

    cin >> r1 >> c1 >> r2 >> c2;

    queue<pair<int, int>> q;
    q.push({r1, c1});
    dist[r1][c1] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!inArea(nx, ny)) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << dist[r2][c2];

    return 0;
}
