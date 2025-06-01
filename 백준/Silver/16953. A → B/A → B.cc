#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;
#define INF 1000000000

using namespace std;

ll A, B;
struct val {
    ll value, count;
};

int solve() {
    queue <val> q;
    q.push({A, 1});

    while (!q.empty()) {
        auto [cur, cnt] = q.front(); q.pop();
        if (cur == B) {
            return cnt;
        }

        if (cur * 2 <= INF  && cur * 2 <= B) {
            q.push({cur*2, cnt + 1});
        }

        if (cur * 10 + 1 <= 1e9 && cur * 10 + 1 <= B) {
            q.push({cur * 10 + 1, cnt + 1});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> A >> B;

    cout << solve();

    return 0;
}