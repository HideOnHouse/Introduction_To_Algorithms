#include <iostream>
using namespace std;

/*
 * 백준 1037번
 * 내가 혐오하는 알고리즘이랑은 별로 관련없이 능지를 물어보는 문제
 * 문제는 함정이고, 약수중에 그냥 제일 작은것과 제일 큰것을 곱하면 된다
 * 제일 작은 약수로 나누면 제일 큰 약수가 발생하기 때문
 * 제곱수여도 상관없다
 */

int main() {
    int n, temp, min_aliquot = 1000000, max_aliquot = 2;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp < min_aliquot) {
            min_aliquot = temp;
        }
        if (temp > max_aliquot) {
            max_aliquot = temp;
        }
    }
    cout << min_aliquot * max_aliquot << endl;
    return 0;
}