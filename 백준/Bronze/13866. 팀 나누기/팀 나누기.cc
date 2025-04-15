#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> team(4);
    for (int i = 0; i < 4; i++) cin >> team[i];

    sort(team.begin(), team.end());

    cout << abs(team[3] + team[0] - team[1] - team[2]);
    return 0;
}