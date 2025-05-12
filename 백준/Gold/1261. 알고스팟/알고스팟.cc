#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF 1e9

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M;

bool inArea(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;

    vector<vector<int>> spot(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            spot[i][j] = s[j] - '0';
        }
    }

    vector<vector<int>> dist(N, vector<int>(M, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, 0, 0);

    while (!pq.empty()) {
        auto [cBreak, cX, cY] = pq.top(); pq.pop();
        if (cX == N-1 && cY == M-1) {
            cout << cBreak;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cX + dx[i];
            int ny = cY + dy[i];

            if (!inArea(nx, ny)) continue;

            int k = (spot[nx][ny] == 1);
            if (dist[nx][ny] > cBreak + k) {
                dist[nx][ny] = cBreak + k;
                pq.emplace(dist[nx][ny], nx, ny);
            }
        }
    }

    return 0;
}