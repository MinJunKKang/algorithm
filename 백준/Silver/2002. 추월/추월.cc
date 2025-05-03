#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    unordered_map<string, int> daegeun;
    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        daegeun.insert({tmp, i});
    }

    queue<string> youngsik;
    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        youngsik.push(tmp);
    }

    vector<bool> visited(N, false);
    int result = 0, pos = 0;
    while (!youngsik.empty()) {
        string k = youngsik.front(); youngsik.pop();
        int tmp = daegeun.find(k)->second;
        if (tmp == pos) {
            visited[pos] = true;
            while (visited[pos]) {
                pos++;
            }
        } else {
            visited[tmp] = true;
            result++;
        }
    }
    cout << result;

    return 0;
}
