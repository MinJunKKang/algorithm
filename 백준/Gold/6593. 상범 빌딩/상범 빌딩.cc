#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int L= 1, R = 1, C = 1;
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0 ,0};
int dz[6] = {0, 0, 0, 0, -1, 1};
vector<vector<vector<char>>> building;
vector<vector<vector<int>>> dist;
bool inArea(int z, int x, int y) {
    return (x >= 0 && x < R && y >= 0 && y < C && z >= 0 && z < L);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        building.assign(L, vector<vector<char>>(R, vector<char>(C)));
        dist.assign(L, vector<vector<int>>(R, vector<int>(C, -1)));
        queue<tuple<int, int, int>> q;

        int goal_z, goal_x, goal_y;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> building[i][j][k];
                    if (building[i][j][k] == 'S') {
                        q.push({i, j, k});
                        dist[i][j][k] = 0;
                    } else if (building[i][j][k] == 'E') {
                        goal_z = i;
                        goal_x = j;
                        goal_y = k;
                    };
                }
            }
        }

        while (!q.empty()) {
            auto [cur_z, cur_x, cur_y] = q.front();
            q.pop();

            if (cur_z == goal_z && cur_x == goal_x && cur_y == goal_y) {
                break;
            }
            for (int i = 0; i < 6; i++) {
                int nz = cur_z + dz[i];
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];

                if (!inArea(nz, nx, ny)) continue;
                if (dist[nz][nx][ny] != -1 || building[nz][nx][ny] == '#') continue;
                dist[nz][nx][ny] = dist[cur_z][cur_x][cur_y] + 1;
                q.push({nz, nx, ny});
            }
        }

        if (dist[goal_z][goal_x][goal_y] == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << dist[goal_z][goal_x][goal_y] << " minute(s).\n";
    }

    return 0;
}
