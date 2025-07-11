#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct Node{
    int x, y;
    int used;
};

int N, M, K;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inArea(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    vector<vector<int>> wall(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < M; j++) {
            wall[i][j] = row[j] - '0';
        }
    }

    vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(K+1, -1)));
    queue<Node> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty()) {
        auto [x, y, used] = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!inArea(nx, ny)) continue;

            if (wall[nx][ny] == 0 && dist[nx][ny][used] == -1) {
                dist[nx][ny][used] = dist[x][y][used] + 1;
                q.push({nx, ny, used});
            }
            else if (wall[nx][ny] == 1 && used < K && dist[nx][ny][used+1] == -1) {
                dist[nx][ny][used+1] = dist[x][y][used] + 1;
                q.push({nx, ny, used+1});
            }
        }
    }

    int ans = INF;

    for (int i = 0; i <= K; i++) {
        if (dist[N-1][M-1][i] == -1) continue;
        ans = min(dist[N-1][M-1][i], ans);
    }

    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}