#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> F >> S >> G >> U >> D;

    vector<int> dist(F+1, -1);
    queue<int> q;
    q.push(S);
    dist[S] = 0;

    while (!q.empty()) {
        int pos = q.front(); q.pop();

        if (pos == G) {
            cout << dist[pos];
            return 0;
        }

        int move_up = pos + U;
        int move_down = pos - D;

        if (move_down > 0) {
            if (dist[move_down] == -1) {
                q.push(move_down);
                dist[move_down] = dist[pos] + 1;
            }
        }

        if (move_up <= F) {
            if (dist[move_up] == -1) {
                q.push(move_up);
                dist[move_up] = dist[pos] + 1;
            }
        }
    }

    cout << "use the stairs";

    return 0;
}