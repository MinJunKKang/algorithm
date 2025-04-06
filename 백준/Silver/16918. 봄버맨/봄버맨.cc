#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int R, C, N;
vector<vector<char>> bomb;
queue<pair<int, int>> bombPos;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void fill() {
    for (int I = 0; I < R; I++) {
        for (int II = 0; II < C; II++) {
            if (bomb[I][II] == 'O') bombPos.push({I, II});
            else bomb[I][II] = 'O';
        }
    }
}

void boom() {
    while (!bombPos.empty()) {
        auto[cur_x, cur_y] = bombPos.front();
        bomb[cur_x][cur_y] = '.';
        bombPos.pop();

        for (int I = 0; I < 4; I++) {
            int nx = cur_x + dx[I];
            int ny = cur_y + dy[I];

            if (!inArea(nx, ny) || bomb[nx][ny] == '.') continue;

            bomb[nx][ny] = '.';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
     * bomb -> 1 (initial)
     * -> 2 (full)
     * -> 3 bomb
     * -> 4 (full)
     * -> ...
     */
    cin >> R >> C >> N;
    bomb.resize(R, vector<char>(C));
    for (int I = 0; I < R; I++) {
        for (int II = 0; II < C; II++) cin >> bomb[I][II];
    }
    
    for (int I = 1; I < N; I++) {
        if (I % 2 == 1) fill();
        if (I % 2 == 0) boom();
    }

    for (int I = 0; I < R; I++) {
        for (int II = 0; II < C; II++) cout << bomb[I][II];
        cout << '\n';
    }

    return 0;
}