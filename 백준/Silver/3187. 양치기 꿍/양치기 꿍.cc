#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;

int dx[6] = {-1, 0, 1, 0};
int dy[6] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    vector<vector<char>> grid(R, vector<char>(C));
    int v_count = 0, k_count = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'v') v_count++;
            else if (grid[i][j] == 'k') k_count++;
        }
    }

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (visited[i][j] || grid[i][j] == '#') continue;
            int tmp_v = 0, tmp_k = 0;
            if (grid[i][j] == '.') {
                q.push({i, j});
                visited[i][j] = true;
            } else if (grid[i][j] == 'v') {
                tmp_v++;
                q.push({i, j});
                visited[i][j] = true;
            } else if (grid[i][j] == 'k') {
                tmp_k++;
                q.push({i, j});
                visited[i][j] = true;
            }

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (!inArea(nx, ny) || visited[nx][ny]) continue;
                    if (grid[nx][ny] == '#') continue;

                    if (grid[nx][ny] == 'k') tmp_k++;
                    else if (grid[nx][ny] == 'v') tmp_v++;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }

            if (tmp_v < tmp_k) v_count -= tmp_v;
            else k_count -= tmp_k;
        }
    }

    cout << k_count << " " << v_count;

    return 0;
}
