#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max_size = 0;
    int min_num = 100001;

    int n;
    cin >> n;

    queue<int> k;
    while (n--) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            int student_num;
            cin >> student_num;
            k.push(student_num);
            if (k.size() > max_size) {
                max_size = k.size();
                min_num = student_num; 
            } else if (k.size() == max_size) {
                min_num = min(min_num, student_num);
            }
        } else {
            k.pop();
        }
    }

    cout << max_size << " " << min_num;

    return 0;
}