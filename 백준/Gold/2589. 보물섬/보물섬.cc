#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define INF 1e9

int R, C;
vector<vector<char>> bomulsum;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool inArea(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int bfs(int s_x, int s_y) {
    vector<vector<int>> dist(R, vector<int>(C, INF));
    queue<pair<int, int>> q;
    q.push(make_pair(s_x, s_y));
    dist[s_x][s_y] = 0;
    int max_dist = dist[s_x][s_y];

    while (!q.empty()) {
        auto [cur_x, cur_y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            int new_dist = dist[cur_x][cur_y] + 1;

            if (inArea(nx, ny) && bomulsum[nx][ny] == 'L') {
                if (dist[nx][ny] > new_dist) {
                    dist[nx][ny] = new_dist;
                    q.push({nx, ny});
                    max_dist = max(max_dist, new_dist);
                }
            }
        }
    }

    return max_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    bomulsum.resize(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cin >> bomulsum[i][j];
    }

    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (bomulsum[i][j] == 'L') {
                ans = max(ans, bfs(i, j));
            }
        }
    }

    cout << ans;

    return 0;
}
