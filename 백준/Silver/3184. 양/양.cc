#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int R, C;

bool inArea(int x, int y) {
    return x >= 0 & x < R && y >= 0 && y < C;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    vector<vector<char>> grid(R, vector<char>(C));
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    int o_num = 0, v_num = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'o') o_num++;
            else if (grid[i][j] == 'v') v_num++;
        }
    }

    queue<pair<int, int>> pos;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int o_size = 0, v_size = 0;
            if (!visited[i][j]) {
                if (grid[i][j] == 'o') {
                    pos.push({i, j});
                    visited[i][j] = true;
                    o_size++;
                } else if (grid[i][j] == 'v') {
                    pos.push({i, j});
                    visited[i][j] = true;
                    v_size++;
                }
            }

            while (!pos.empty()) {
                auto [cur_x, cur_y] = pos.front();
                pos.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = cur_x + dx[k];
                    int ny = cur_y + dy[k];

                    if (!inArea(nx, ny)) continue;
                    if (grid[nx][ny] == '#' || visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    pos.push({nx, ny});
                    if (grid[nx][ny] == 'o') o_size++;
                    if (grid[nx][ny] == 'v') v_size++;

                }
            }

            if (o_size > v_size) v_num -= v_size;
            else o_num -= o_size;
        }
    }

    cout << o_num << " " << v_num;

    return 0;
}