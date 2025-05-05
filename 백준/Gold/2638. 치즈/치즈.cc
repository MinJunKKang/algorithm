#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> cheese(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> cheese[i][j];
    }

    int T = 0;
    queue<pair<int, int>> q;

    while (true) {
        int cheese_size = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cheese[i][j] == 1) cheese_size++;
            }
        }

        // 종료 조건
        if (cheese_size == 0) break;
        // 종료하지 않았을 경우 T 증가
        T++;
        vector<vector<int>> cnt(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!inArea(nx, ny)) continue;
                if (visited[nx][ny]) continue;

                if (cheese[nx][ny] == 0) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                } else {
                    cnt[nx][ny]++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cnt[i][j] >= 2) cheese[i][j] = 0;
            }
        }
    }

    cout << T;

    return 0;
}
