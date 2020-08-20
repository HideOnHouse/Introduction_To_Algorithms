#include <iostream>

using namespace std;
/*
 * "다음 와인을 먹는 경우는 3가지가 있다"
 * 1. 연속된 두개와 떨어진 하나를 먹는 경우 f(n) = f(n - 3) + n - 1 + n
 * 2. 하나를 먹고 떨어진 하나를 먹는 경우 f(n) = f(n - 2) + n
 * 3. 안 먹는 경우 f(n) = f(n - 1)
 */
#define max(x, y) x > y ? x : y

int main() {
    cin.tie(nullptr);
    std::istream::sync_with_stdio(false);
    int count, answer = 0;
    cin >> count;
    int *wines = new int[count + 3]();
    int *temp = new int[count + 3]();
    for (int i = 3; i < count + 3; ++i) {
        cin >> wines[i];
    }
    for (int i = 3; i < count + 3; ++i) {
        temp[i] = max(temp[i - 3] + wines[i - 1] + wines[i], temp[i - 2] + wines[i]);
        temp[i] = max(temp[i], temp[i - 1]);
        answer = max(temp[i], answer);
    }
    cout << answer << '\n';
    return 0;
}
