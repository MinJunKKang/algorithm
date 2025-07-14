#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return (x >= 0 && x < R && y >= 0 && y < C);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    vector<vector<char>> island(R, vector<char>(C));
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++) {
        string line; cin >> line;
        for (int j = 0; j < C; j++) island[i][j] = line[j];
    }

    int answer = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (island[i][j] == 'L' && !visited[i][j]) {
                answer++;
                q.push({i, j});
            }
            visited[i][j] == true;

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (!inArea(nx, ny) || visited[nx][ny]) continue;

                    if (island[nx][ny] == 'L' || island[nx][ny] == 'C') {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }

    cout << answer;


    return 0;
}