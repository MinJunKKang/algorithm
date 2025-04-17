#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    float n;
    cin >> n;

    cout << fixed << setprecision(2);
    cout << n / 4;

    return 0;
}