#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> S(N);
    vector<int> L(N);

    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> L[i];

    vector<int> pos(N+1);
    for (int i = 0; i < N; i++) pos[L[i]] = i;

    vector<int> A(N);
    for (int i = 0; i < N; i++) A[i] = pos[S[i]];

    vector<int> dpVal;
    vector<int> dpIdx;
    vector<int> parent(N, -1);

    for (int i = 0; i < N; i++) {
        int a = A[i];

        int idx = lower_bound(dpVal.begin(), dpVal.end(), a) - dpVal.begin();
        if (idx == dpVal.size()) {
            dpVal.push_back(a);
            dpIdx.push_back(i);
        } else {
            dpVal[idx] = a;
        }

        if (idx > 0) parent[i] = dpIdx[idx - 1];
        dpIdx[idx] = i;
    }

    vector<char> keep(N, 0);
    for (int cur = dpIdx.back(); cur != -1; cur = parent[cur])
        keep[cur] = 1;

    vector<int> remainList;
    for (int i = 0; i < N; i++) {
        if (keep[i]) remainList.push_back(S[i]);
    }

    sort(remainList.begin(), remainList.end());

    cout << remainList.size() << '\n';
    for (int x: remainList) cout << x << " ";

    return 0;
}