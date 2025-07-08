#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    int answer = 0;
    
    int vec_len = numbers.size();
    answer = numbers[vec_len-1] * numbers[vec_len - 2];
    return answer;
}