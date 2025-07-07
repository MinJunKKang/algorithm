#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    int M; cin >> M;

    vector<int> Pos(M);
    for (int &x: Pos) cin >> x;

    int H = Pos[0];
    H = max(H, N - Pos.back());

    for (int i = 0; i < M-1; i++) {

        H = max(H, (Pos[i+1]-Pos[i] + 1) / 2);
    }
    cout << H;

    return 0;
}