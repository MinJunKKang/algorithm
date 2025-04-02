#include <iostream>
#include <stack>

using namespace std;
int N;
stack<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int result = 0;
    for (int i = 0; i < N; i++) {
        int flag;
        cin >> flag;

        if (flag == 1) {
            int score, time;
            cin >> score >> time;
            s.push({score, time});
        }

        if (!s.empty()) {
            auto topTask = s.top();
            s.pop();
            topTask.second--;

            if (topTask.second == 0) result += topTask.first;
            else s.push({topTask.first, topTask.second});
        }
    }

    cout << result;

    return 0;
}