#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double weight, height;
    cin >> weight;
    cin >> height;

    double result = weight / (height * height);

    if (result > 25) cout << "Overweight";
    else if (result >= 18.5) cout << "Normal weight";
    else cout << "Underweight";


    return 0;
}