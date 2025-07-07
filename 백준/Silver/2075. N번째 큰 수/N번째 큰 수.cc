#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    if (!(cin >> N)) return 0;

    priority_queue<int, vector<int>, greater<>> pq;

    int k = N * N;

    for (int i = 0; i < k; ++i) {
        int t; cin >> t;
        pq.push(t);

        if (pq.size() > N) pq.pop();
    }

    cout << pq.top();

    return 0;
}