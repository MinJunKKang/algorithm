#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<vector<int>> shark(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int,int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> shark[i][j];
            if (shark[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (!inArea(nx, ny)) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            answer = max(answer, dist[i][j]);
        }
    }

    cout << answer;
    return 0;
}
