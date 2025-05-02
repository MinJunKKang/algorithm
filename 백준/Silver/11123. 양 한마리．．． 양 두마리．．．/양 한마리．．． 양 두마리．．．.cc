#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int H, W;
bool inArea(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0 ,-1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> H >> W;
        vector<vector<char>> grid(H, vector<char>(W));
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        for (int I = 0; I < H; I++) {
            string tmp;
            cin >> tmp;
            for (int II = 0; II < W; II++) {
                grid[I][II] = tmp[II];
            }
        }

        queue<pair<int, int>> q;
        int result = 0;
        for (int I = 0; I < H; I++) {
            for (int II = 0; II < W; II++) {
                if (grid[I][II] == '#' && !visited[I][II]) {
                    q.push({I, II});
                    visited[I][II] = true;
                    result++;
                }

                while (!q.empty()) {
                    auto [cur_x, cur_y] = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = cur_x + dx[i];
                        int ny = cur_y + dy[i];

                        if (!inArea(nx, ny)) continue;
                        if (visited[nx][ny]) continue;
                        if (grid[nx][ny] == '#') {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
        cout << result << '\n';
    }

    return 0;
}
