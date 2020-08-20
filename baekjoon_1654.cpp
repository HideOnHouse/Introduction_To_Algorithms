#include <iostream>
using namespace std;
/*
 * 단순한 이진탐색 문제입니다.
 * 문제에서 N값이 크다는 것에서 힌트를 얻을 수 있다.
 * 처음에는 1씩 감소하면서 정답을 찾았는데, 예상했던데로 시간 초과 오류가 발생
 *
 */
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    unsigned int K, N, low, high, mid, cable_sum;
    cin >> K >> N;
    unsigned int length_arr[10000]{0,};
    for (int i = 0; i < K; ++i) {
        cin >> length_arr[i];
    }
    low = 1;
    high = 2147483647;
    while (low <= high) {
        mid = (high + low) / 2;
        cable_sum = 0;
        for (int i = 0; i < K; ++i) {
            cable_sum += length_arr[i] / mid;
            if (cable_sum > N) {
                break;
            }
        }
        if (cable_sum >= N) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << high << '\n';
    return 0;
}