#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

struct pos{
    int x, y, dist;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> move_map(n, vector<int>(m));
    pair<int, int> goal_pos;

    for (int I = 0; I < n; I++) {
        for (int II = 0; II < m; II++) {
            cin >> move_map[I][II];
            if (move_map[I][II] == 2)
                goal_pos = {I, II};
        }
    }

    queue<pos> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> result_map(n, vector<int>(m, -1));
    q.push({goal_pos.first, goal_pos.second, 0});
    visited[goal_pos.first][goal_pos.second] = true;

    while (!q.empty()) {
        auto [cur_x, cur_y, cur_dist] = q.front();
        result_map[cur_x][cur_y] = cur_dist;
        q.pop();

        for (int I = 0; I < 4; I++) {
            int nx = cur_x + dx[I];
            int ny = cur_y + dy[I];

            if (!inArea(nx, ny)) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            if (move_map[nx][ny] == 0) result_map[nx][ny] = 0;
            else {
                result_map[nx][ny] = cur_dist+1;
                q.push({nx, ny, cur_dist+1});
            }
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (move_map[i][j] == 0) result_map[i][j] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result_map[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}