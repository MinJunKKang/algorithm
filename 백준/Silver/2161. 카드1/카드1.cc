#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> card;
    for (int i = 1; i <= N; i++) {
        card.push(i);
    }

    while (!card.empty()) {
        cout << card.front() << " ";
        card.pop();

        if (card.empty()) break;

        int tmp = card.front();
        card.pop();
        card.push(tmp);
    }


    return 0;
}