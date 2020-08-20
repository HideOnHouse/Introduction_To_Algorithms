#include <iostream>

using namespace std;
/*
 * 그림 3번만 그려보면 점화식이 명확히 나옵니다
 * f(n) = f(n - 1) + f(n - 5)
 */
int main() {
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        long long dp[101];
        dp[0] = dp[1] = dp[2] = dp[3] = 1, dp[4] = dp[5] = 2;
        for (int j = 6; j <= N; j++) {
            dp[j] = dp[j - 1] + dp[j - 5];
        }
        cout << dp[N] << "\n";
    }
    return 0;
}