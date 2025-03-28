#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;

int max_result = -1e9;
int min_result = 1e9;

void dfs(int idx, int sum, int plus, int minus, int mul, int div) {
    if (idx == N) {
        max_result = max(max_result, sum);
        min_result = min(min_result, sum);
        return;
    }

    if (plus > 0)
        dfs(idx+1, sum+A[idx], plus-1, minus, mul, div);
    if (minus > 0)
        dfs(idx+1, sum-A[idx], plus, minus-1, mul, div);
    if (mul > 0)
        dfs(idx+1, sum*A[idx], plus, minus, mul-1, div);
    if (div > 0) {
        int next;
        if (sum < 0) {
            next = -(-sum / A[idx]);
        } else next = sum / A[idx];
        dfs(idx+1, next, plus, minus, mul, div-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    A.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;

    dfs(1, A[0], plus, minus, mul, div);

    cout << max_result << '\n' << min_result << '\n';

    return 0;
}