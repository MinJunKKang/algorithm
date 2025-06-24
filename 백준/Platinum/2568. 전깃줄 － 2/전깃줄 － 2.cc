#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Wire {
    int a, b;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<Wire> wire(N);
    for (auto &x: wire) cin >> x.a >> x.b;

    sort(wire.begin(), wire.end(),
        [](const Wire &x, const Wire &y) {return x.a < y.a; });

    vector<int> dpVal;
    vector<int> dpIdx;
    vector<int> parent(N, -1);

    for (int i = 0; i < N; i++) {
        int b = wire[i].b;
        int idx = lower_bound(dpVal.begin(), dpVal.end(), b) - dpVal.begin();

        if (idx == dpVal.size()) {
            dpVal.push_back(b);
            dpIdx.push_back(i);
        } else {
            dpVal[idx] = b;
        }

        if (idx > 0) parent[i] = dpIdx[idx - 1];
        dpIdx[idx] = i;
    }

    vector<char> keep(N, 0);
    for (int cur = dpIdx.back(); cur != -1; cur = parent[cur])
        keep[cur] = 1;

    vector<int> eraseList;
    for (int i = 0; i < N; ++i) {
        if (!keep[i]) eraseList.push_back(wire[i].a);
    }
    
    cout << eraseList.size() << '\n';
    for (int x: eraseList) cout << x << '\n';


    return 0;
}