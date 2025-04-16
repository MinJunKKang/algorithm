#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max_val = 0;

    string l;
    for (int i = 0; i < 7; i++) {
        string temp_l;
        int temp;
        cin >> temp_l >> temp;
        if (temp > max_val) {
            max_val = temp;
            l = temp_l;
        }
    }

    cout << l;
    return 0;
}