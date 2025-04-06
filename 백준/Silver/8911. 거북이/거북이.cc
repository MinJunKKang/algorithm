#include <iostream>
#include <vector>

using namespace std;

// UP, LEFT, DOWN, RIGHT
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        string command;
        cin >> command;

        pair<int, int> pos = {0, 0};
        int mod = 0;
        int max_x = 0, min_x = 0, max_y = 0, min_y = 0;

        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'L') {
                mod = (mod + 1) % 4;
            } else if (command[i] == 'R') {
                mod = mod - 1;
                if (mod < 0) mod+=4;
            } else if (command[i] == 'F') {
                pos.first += dx[mod];
                pos.second += dy[mod];
            } else if (command[i] == 'B') {
                pos.first += dx[(mod+2)%4];
                pos.second += dy[(mod+2)%4];
            }

            max_x = max(pos.first, max_x);
            min_x = min(pos.first, min_x);
            max_y = max(pos.second, max_y);
            min_y = min(pos.second, min_y);
        }

        cout << (max_x - min_x) * (max_y - min_y) << '\n';
    }

    return 0;
}