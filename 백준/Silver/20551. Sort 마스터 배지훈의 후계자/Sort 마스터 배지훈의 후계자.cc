#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    while (M--) {
        int D; cin >> D;

        auto it = lower_bound(A.begin(), A.end(), D);
        if (it == A.end() || *it != D) cout << -1;
        else cout << it - A.begin();
        cout << '\n';
    }

    return 0;
}
