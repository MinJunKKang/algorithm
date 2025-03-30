#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> grid;

int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    grid.resize(N, vector<int>(N));

    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) cin >> grid[i][j];
    }

    vector<pair<int, int>> cloud;
    cloud.push_back({N-2, 0});
    cloud.push_back({N-2, 1});
    cloud.push_back({N-1, 0});
    cloud.push_back({N-1, 1});

    while (M--) {
        int d, s;
        cin >> d >> s;

        for (auto &c: cloud) {
            int x = c.first;
            int y = c.second;

            int nx = (x + dx[d] * s) % N;
            int ny = (y + dy[d] * s) % N;

            if (nx < 0) nx += N;
            if (ny < 0) ny += N;

            c.first = nx;
            c.second = ny;
        }

        vector<vector<bool>> visited(N, vector<bool>(N, false));
        for (auto &c: cloud) {
            int x = c.first; int y = c.second;
            grid[x][y] +=1;
            visited[x][y] = true;
        }

        for (auto &c: cloud) {
            int x = c.first; int y = c.second;
            int cnt = 0;

            for (int i = 2; i <= 8; i+=2) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] > 0) {
                    cnt++;
                }
            }
            grid[x][y] += cnt;
        }

        vector<pair<int,int>> newClouds;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (!visited[i][j] && grid[i][j] >= 2){
                    newClouds.push_back({i, j});
                    grid[i][j] -= 2;
                }
            }
        }

        cloud = newClouds;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            ans += grid[i][j];
        }
    }

    cout << ans;

    return 0;
}