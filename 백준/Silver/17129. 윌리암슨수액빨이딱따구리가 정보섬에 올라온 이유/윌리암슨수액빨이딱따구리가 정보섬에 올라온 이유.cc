#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;

bool inArea(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    queue<pair<int, int>> q;
    vector<vector<int>> mat(n, vector(m, 0));
    vector<vector<bool>> visited(n, vector(m, false));
    vector<vector<int>> dist(n, vector(m, 0));

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            mat[i][j] = str[j] - '0';
            if (mat[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [cur_x, cur_y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (!inArea(nx, ny) || visited[nx][ny] || mat[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[cur_x][cur_y] + 1;
            if (mat[nx][ny] != 0) {
                cout << "TAK\n" << dist[nx][ny];
                return 0;
            }
            q.push({nx, ny});
        }
    }

    cout << "NIE";

    return 0;
}