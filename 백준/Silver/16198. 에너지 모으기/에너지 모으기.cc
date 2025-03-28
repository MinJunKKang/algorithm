#include <iostream>
#include <vector>

using namespace std;
vector<int> W;

int N;
int max_energy = 0;

void dfs(vector<int> v, int energy) {
    if (v.size() == 2) {
        max_energy = max(max_energy, energy);
        return;
    }

    for (int i = 1; i < v.size() - 1; i++) {
        int gain = v[i-1] * v[i+1];

        vector<int> new_v = v;
        new_v.erase(new_v.begin() + i);

        dfs(new_v, energy + gain);
    }

    return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    W.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    dfs(W, 0);

    cout << max_energy;

    return 0;
}