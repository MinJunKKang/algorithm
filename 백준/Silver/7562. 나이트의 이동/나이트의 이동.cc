#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, l;
bool inArea(int x, int y) {
    return x >= 0 && x < l && y >= 0 && y < l;
}

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {-1, 1, -2 ,2, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> l;
        vector<vector<int>> dist(l, vector<int>(l, -1));
        queue<pair<int, int>> q;

        int cur_x, cur_y;
        int goal_x, goal_y;
        cin >> cur_x >> cur_y;
        cin >> goal_x >> goal_y;

        dist[cur_x][cur_y] = 0;
        q.push({cur_x, cur_y});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == goal_x && y == goal_y) {
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!inArea(nx, ny)) continue;
                if (dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
        cout << dist[goal_x][goal_y] << '\n';
    }

    return 0;
}