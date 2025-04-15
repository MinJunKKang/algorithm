#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        double X;
        cin >> X;

        if (X < 0) break;

        double Y = X * 0.167;

        cout << fixed << setprecision(2);
        cout << "Objects weighing " << X << " on Earth will weigh " <<  Y <<  " on the moon.\n";
    }

    return 0;
}