#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, X;
    cin >> T >> X;

    int N;
    cin >> N;

    bool result = true;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        vector<int> A(K);
        for (int j = 0; j < K; j++) cin >> A[j];
        auto it = lower_bound(A.begin(), A.end(), X);
        if (it == A.end() || *it != X) result = false;
    }

    if (result) cout << "YES";
    else cout << "NO";

    return 0;
}