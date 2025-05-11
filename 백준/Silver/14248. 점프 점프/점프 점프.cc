#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, s;
bool inArea(int x) {
    return x > 0 && x <= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> A(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    cin >> s;

    queue<int> q;
    int result = 0;
    vector<bool> visited(n+1, false);

    q.push(s);
    result++;
    visited[s] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        int lft = x - A[x];
        int rgt = x + A[x];

        if (inArea(lft)) {
            if (!visited[lft]) {
                result++;
                visited[lft] = true;
                q.push(lft);
            }
        }
        if (inArea(rgt)) {
            if (!visited[rgt]) {
                result++;
                visited[rgt] = true;
                q.push(rgt);
            }
        }
    }

    cout << result;

    return 0;
}
