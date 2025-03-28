#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define INF 1e15

int N;
vector<int> S, B;
vector<bool> visited;
ll min_result = INF;

void calculate() {
    ll S_result = 1, B_result = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            S_result *= S[i];
            B_result += B[i];
        }
    }

    min_result = min(min_result, llabs(S_result - B_result));
}

void dfs(int idx) {
    if (idx == N) {
        bool atleasted = false;

        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                atleasted = true;
                break;
            }
        }

        if (atleasted) calculate();
        return;
    }

    visited[idx] = true;
    dfs(idx + 1);

    visited[idx] = false;
    dfs(idx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    S.resize(N); B.resize(N);
    visited.assign(N, false);

    for (int i = 0; i < N; i++) {
        cin >> S[i] >> B[i];
    }

    dfs(0);
    cout << min_result;

    return 0;
}