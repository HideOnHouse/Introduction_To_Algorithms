#include <iostream>

using namespace std;
/*
 * 이진 탐색 문제
 * M이 매우 큰 부분에 주목해야 한다
 * 이진 탐색 문제는 대부분 정답을 이진 탐색으로 찾으라는 문제이다
 */

int main() {
    unsigned long long N, M, low, high, mid, max_height = 0, total, answer = 0;
    cin >> N >> M;
    unsigned long long H[N];
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        if (H[i] > max_height) {
            max_height = H[i];
        }
    }
    low = 0;
    high = max_height;
    while (low <= high) {
        mid = (low + high) / 2;
        total = 0;
        for (const auto &h : H) {
            if (mid < h) {
                total += h - mid;
            }
        }
        if (total >= M) {
            if (mid > answer) {
                answer = mid;
            }
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}