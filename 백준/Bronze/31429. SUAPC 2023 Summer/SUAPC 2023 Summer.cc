#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> k(12);

    k[1] = {12, 1600};
    k[2] = {11, 894};
    k[3] = {11, 1327};
    k[4] = {10, 1311};
    k[5]= {9, 1004};
    k[6] = {9, 1178};
    k[7] = {9, 1357};
    k[8] = {8, 837};
    k[9] = {7, 1055};
    k[10]= {6, 556};
    k[11] = {6, 773};

    int N;
    cin >> N;

    cout << k[N].first << " " << k[N].second;

    return 0;
}