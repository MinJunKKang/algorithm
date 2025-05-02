#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 벽 부수기 카운트
struct Node {
    int x, y;
    int used;
};
// 행, 열
int N, M;
// 주어진 범위 안에 있는가?
bool inArea(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}
// 이동 방향
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> wall(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < M; j++) {
            wall[i][j] = row[j] - '0';
        }
    }

    vector<vector<vector<int>>> dist(N,vector<vector<int>>(M, vector<int>(2, -1)));
    queue<Node> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty()) {
        auto [x, y, used] = q.front(); q.pop();

        for (int i = 0 ; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!inArea(nx, ny)) continue;

            if (wall[nx][ny] == 0 && dist[nx][ny][used] == -1) {
                dist[nx][ny][used] = dist[x][y][used] + 1;
                q.push({nx, ny, used});
            } else if (wall[nx][ny] == 1 && used == 0 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[x][y][used] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    int a = dist[N-1][M-1][0];
    int b = dist[N-1][M-1][1];
    int ans;

    if (a == -1 && b == -1) ans = -1;
    else if (a == -1) ans = b;
    else if (b == -1) ans = a;
    else ans = min(a, b);

    cout << ans << "\n";

    return 0;
}
