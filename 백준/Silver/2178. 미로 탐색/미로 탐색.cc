#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    grid.resize(R, vector<int>(C));
    visited.resize(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    queue<pair<int, int>> pos;
    pos.push({0, 0});
    visited[0][0] = true;

    int cnt = 1;
    bool its_over = false;

    while (true) {
        cnt++;
        int q_size = pos.size();
        for (int i = 0; i < q_size; i++) {
            auto [cur_x, cur_y] = pos.front();
            pos.pop();

            for (int j = 0; j < 4; j++) {
                int nx = cur_x + dx[j];
                int ny = cur_y + dy[j];

                if (!inArea(nx, ny)) continue;

                if (nx == R-1 && ny == C-1) its_over = true;

                if (!visited[nx][ny] && grid[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    pos.push({nx, ny});
                }
            }
        }
        if (its_over) break;
    }

    cout << cnt;

    return 0;
}