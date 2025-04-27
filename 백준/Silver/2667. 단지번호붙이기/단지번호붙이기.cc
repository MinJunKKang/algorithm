#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> apart;
vector<vector<bool>> visited;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

vector<int> bfs() {
    queue<pair<int, int>> q;
    vector<int> result;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            int tmp = 1;
            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                auto [cur_x, cur_y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = cur_x + dx[k];
                    int ny = cur_y + dy[k];

                    if (!inArea(nx, ny)) continue;
                    if (visited[nx][ny]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    tmp++;
                }
            }
            result.push_back(tmp);
        }
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    apart.resize(N, vector<int>(N));
    visited.assign(N, vector<bool>(N, false));
    string line;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < N; j++) {
            apart[i][j] = line[j] - '0';
            visited[i][j] = (apart[i][j] == 0);
        }
    }

    vector<int> k = bfs();
    int k_size = k.size();
    cout << k_size << '\n';
    for (int i = 0; i < k_size; i++) cout << k[i] << '\n';

    return 0;
}