#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<int> height(W);

    for (int i = 0; i < W; i++) cin >> height[i];

    vector<vector<int>> grid(H, vector<int>(W, 0));

    for (int I = 0; I < W; I++) {
        int cur_height = height[I];
        for (int II = H-1; II >= (H - cur_height); II--)
            grid[II][I] = 1;
    }

    int result = 0;
    for (int I = 0; I < H; I++) {
        bool k = false;
        int cnt = 0;
        for (int II = 0; II < W; II++) {
            if (k == false) {
                if (grid[I][II] == 1) k = true;
            } else {
                if (grid[I][II] == 0) cnt++;
                else {
                    result+= cnt;
                    cnt = 0;
                }
            }
        }
    }

    cout << result;

    return 0;
}