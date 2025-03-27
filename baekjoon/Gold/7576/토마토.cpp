#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int C, R;
vector<vector<int>> tomato;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool inArea(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            if (tomato[i][j] == 1) q.push(make_pair(i, j));
    }

    while (!q.empty()) {
        auto [cur_x, cur_y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (!inArea(nx, ny) || tomato[nx][ny] == -1) continue;

            if (tomato[nx][ny] == 0) {
                tomato[nx][ny] = tomato[cur_x][cur_y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C >> R;

    tomato.resize(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cin >> tomato[i][j];
    }

    bfs();

    int max_day = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (tomato[i][j] == 0) {
                cout << -1;
                return 0;
            } else {
                max_day = max(max_day, tomato[i][j]);
            }
        }
    }

    cout << max_day - 1;

    return 0;
}
