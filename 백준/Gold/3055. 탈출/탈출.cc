#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
vector<vector<char>> grid;
queue<pair<int, int>> water;
queue<pair<int, int>> doci;
int t = 0;

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
    grid.resize(R, vector<char>(C));
    
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') water.push({i, j});
            else if (grid[i][j] == 'S') doci.push({i, j});
        }
    }

    while (!doci.empty()) {
        int water_size = water.size();
        for (int i = 0; i < water_size; i++) {
            auto [cur_x, cur_y] = water.front();
            water.pop();

            for (int j = 0; j < 4; j++) {
                int nx = cur_x + dx[j];
                int ny = cur_y + dy[j];

                if (!inArea(nx, ny)) continue;

                if (grid[nx][ny] == '.') {
                    grid[nx][ny] = '*';
                    water.push({nx, ny});
                }
            }
        }
        t++;
        
        int doci_size = doci.size();
        for (int i = 0; i < doci_size; i++) {
            auto [cur_x, cur_y] = doci.front();
            visited[cur_x][cur_y] = true;
            doci.pop();

            for (int j = 0; j < 4; j++) {
                int nx = cur_x + dx[j];
                int ny = cur_y + dy[j];

                if (!inArea(nx, ny)) continue;
                
                if (grid[nx][ny] == 'D') {
                    cout << t;
                    return 0;
                }

                if (grid[nx][ny] == '.' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    doci.push({nx, ny});
                }
            }
        }
    }

    cout << "KAKTUS";

    return 0;
}