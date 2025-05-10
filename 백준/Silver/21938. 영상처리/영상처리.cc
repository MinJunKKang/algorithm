#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int T;

bool inArea(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int r, g, b;
            cin >> r >> g >> b;
            grid[i][j] = (r + g + b) / 3;
        }
    }

    cin >> T;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] >= T) grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                q.push({i, j});
                ans++;
                visited[i][j] = true;
            }

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (!inArea(nx, ny)) continue;
                    if (grid[nx][ny] == 0 || visited[nx][ny]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
