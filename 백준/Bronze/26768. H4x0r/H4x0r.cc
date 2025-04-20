#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string W;
    cin >> W;

    for (int i = 0; i < W.size(); i++) {
        if (W[i] == 'a') cout << 4;
        else if (W[i] == 'e') cout << 3;
        else if (W[i] == 'i') cout << 1;
        else if (W[i] == 'o') cout << 0;
        else if (W[i] == 's') cout << 5;
        else cout << W[i];
    }

    return 0;
}