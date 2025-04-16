#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool can = true;

    int l_count = 0, k_count = 0, p_count = 0;
    for (int i = 0; i < 3; i++) {
        string n;
        cin >> n;
        if (n[0] == 'l') l_count++;
        if (n[0] == 'k') k_count++;
        if (n[0] == 'p') p_count++;
        can = false;
    }

    if (l_count == 0 || k_count == 0 || p_count == 0) cout << "PONIX";
    else cout << "GLOBAL";

    return 0;
}