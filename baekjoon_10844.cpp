#include <iostream>

using namespace std;
/*
 * 1000000000 으로 나눈 나머지 때문에 unsigned long long 이란 큰 수를 사용했어야 했다
 * 앞자리가 0~9인 경우를 각각 생각해보면 쉽게 풀 수 있는 문제였다
 */
int main() {
    cin.tie(nullptr);
    std::istream::sync_with_stdio(false);
    int n;
    cin >> n;
    int A[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int B[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned long long answer = 0;
    for (int i = 1; i < n; i++) {
        B[0] = A[1];
        B[1] = A[0] + A[2];
        B[2] = A[1] + A[3];
        B[3] = A[2] + A[4];
        B[4] = A[3] + A[5];
        B[5] = A[4] + A[6];
        B[6] = A[5] + A[7];
        B[7] = A[6] + A[8];
        B[8] = A[7] + A[9];
        B[9] = A[8];
        for (int j = 0; j < 10; ++j) {
            A[j] = B[j] % 1000000000;
        }
    }
    for (const auto &a : A) {
        answer += a;
    }
    cout << answer % 1000000000 << '\n';
}