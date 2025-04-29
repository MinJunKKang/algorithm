#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;

bool inArea(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    grid.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    }

    int year = 0;
    while (true) {
        visited.assign(N, vector<bool>(M, false));

        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                    cnt++;
                }

                while (!q.empty()) {
                    auto [cur_x, cur_y] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = cur_x + dx[k];
                        int ny = cur_y + dy[k];

                        if (!inArea(nx, ny)) continue;
                        if (visited[nx][ny]) continue;

                        if (grid[nx][ny] != 0) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        } else {
                            grid[cur_x][cur_y]--;
                        }
                    }
                    if (grid[cur_x][cur_y] < 0) grid[cur_x][cur_y] = 0;
                }
            }
        }

        if (cnt == 0) {
            cout << 0;
            return 0;
        }
        if (cnt > 1) break;
        year++;
    }

    cout << year;

    return 0;
}
