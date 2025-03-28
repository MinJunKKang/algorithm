#include <iostream>
#include <queue>

using namespace std;

const int INF = 2147483647;
const int Max_size = 126;

int N;
int thief_rupee[Max_size][Max_size];
int dist[Max_size][Max_size];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool inArea(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

// 다익스트라 알고리즘 적용
int dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    // 초기 상태 설정
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INF;  // 모든 경로 비용을 무한대로 초기화
        }
    }

    // 시작점 설정 (0,0)에서 출발
    dist[0][0] = thief_rupee[0][0];
    pq.push({dist[0][0], {0, 0}});

    while (!pq.empty()) {
        auto [cur_cost, pos] = pq.top();
        int x = pos.first, y = pos.second;
        pq.pop();

        // 현재 위치에서 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (inArea(nx, ny)) {
                int new_cost = cur_cost + thief_rupee[nx][ny];

                if (new_cost < dist[nx][ny]) {  // 더 적은 루피를 잃는 경로라면 갱신
                    dist[nx][ny] = new_cost;
                    pq.push({new_cost, {nx, ny}});
                }
            }
        }
    }

    return dist[N - 1][N - 1];  // (N-1, N-1) 위치에서의 최소 손실 루피 반환
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;

    while (true) {
        cin >> N;

        if (N == 0) return 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> thief_rupee[i][j];
            }
        }

        count++;

        int result = dijkstra();

        cout << "Problem " << count << ": " << result << "\n";
    }
}