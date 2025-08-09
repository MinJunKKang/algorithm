#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return (x >= 0 && x < 10 && y >= 0 && y < 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int, int>> q;
    vector<vector<char>> mat(10, vector<char>(10));
    vector<vector<bool>> visited(10, vector(10, false));
    vector<vector<int>> dist(10, vector(10, 0));

    for (int i = 0; i < 10; i++) {
        string str; cin >> str;
        for (int j = 0; j < 10; j++) {
            mat[i][j] = str[j];
            if (mat[i][j] == 'B') {
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

            if (!inArea(nx, ny) || visited[nx][ny] || mat[nx][ny] == 'R') continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[cur_x][cur_y] + 1;
            if (mat[nx][ny] == 'L') {
                cout << dist[nx][ny] - 1;
                break;
            }
            q.push({nx, ny});
        }
    }

    return 0;
}