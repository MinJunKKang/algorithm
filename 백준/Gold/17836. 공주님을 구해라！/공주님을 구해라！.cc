#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 성의 크기, 제한 시간인 정수 T
    int N, M, T;
    cin >> N >> M >> T;

    int s_x, s_y;

    vector<vector<int>> castle(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> castle[i][j];
            if (castle[i][j] == 2) {
                s_x = i; s_y = j;
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(N, vector<int>(M, INF));
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [cur_x, cur_y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (dist[nx][ny] != INF) continue;
                if (castle[nx][ny] == 1) continue;

                dist[nx][ny] = dist[cur_x][cur_y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int ans = dist[N-1][M-1];


    if (dist[s_x][s_y] != INF) {
        int tmp = ((N-1) - s_x + (M-1) - s_y + dist[s_x][s_y]);
        ans = min(ans, tmp);
    }

    if (ans == INF || ans > T) {
        cout << "Fail";
    } else cout << ans;

    return 0;
}