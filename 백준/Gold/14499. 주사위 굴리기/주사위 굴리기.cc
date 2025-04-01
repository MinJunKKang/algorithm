#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
vector<vector<int>> grid;
vector<int> command;

// 동, 서, 북, 남
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int dice[6] = {0, 0, 0, 0, 0, 0};

void move_north() {
    int temp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[4];
    dice[4] = temp;
}

void move_south() {
    int temp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = temp;
}

void move_east() {
    int temp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = temp;
}

void move_west() {
    int temp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = temp;
}

// 바깥으로 나가는 명령을 제외
bool inArea(int cur_x, int cur_y) {
    return cur_x>=0 && cur_x<N && cur_y>=0 && cur_y<M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> x >> y >> K;
    grid.resize(N, vector<int>(M));

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) cin >> grid[i][j];
    }

    command.resize(K);
    for (int i=0; i<K; i++) {
        cin >> command[i];
    }

    for (int i =0; i < K; i++) {
        int nx = x + dx[command[i]];
        int ny = y + dy[command[i]];

        if (!inArea(nx, ny)) continue;

        switch (command[i]) {
            case 1:
                move_east();
                break;
            case 2:
                move_west();
                break;
            case 3:
                move_north();
                break;
            case 4:
                move_south();
                break;
        }

        if (grid[nx][ny] == 0) {
            grid[nx][ny] = dice[0];
        } else {
            dice[0] = grid[nx][ny];
            grid[nx][ny] = 0;
        }

        x = nx; y = ny;
        cout << dice[5] << '\n';
    }

    return 0;
}