#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            cout << x << " is even\n";
        } else cout << x <<  " is odd\n";
    }
    return 0;
}