#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int d1, d2;
    cin >> d1;
    cin >> d2;

    cout << fixed << setprecision(6);
    cout << double(d1 * 2 + 2 * d2 * 3.141592);

    return 0;
}