#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // 그냥 음수 절대 안나와서 안전하게 unsigned int 로 함.
    unsigned int N, C, max_distance, mid_distance, min_distance, count, temp, answer = 0;
    unsigned int x[200000];
    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    /*
    최대좌표, 최소좌표 찾을려고 정렬. 처음에 정렬한 이유는 최소좌표, 최대좌표
    사이를 최대한 균등하게 나누고 그냥 답 찍어볼려고 했음. 당연히 안됌.
    정렬하면 또 시간초과 날까봐 조마조마했음 최소최대를 찾는게 목적이라 stable sort는 필요없을거라 판단
    */
    sort(x, x + N);
    /*
    처음에는 C를 기준으로 distance가 가능한지
    한참동안 삽질하다가 안되는거 같아서 distance를 기준으로 C가 나오는지 확인
    */
    min_distance = 1;
    max_distance = x[N - 1] - x[0];
    while (min_distance <= max_distance) {
        mid_distance = (max_distance + min_distance) / 2;
        /*
        count = 0 으로 시작해서 10분동안 삽질...
        첫째 집에는 무조건 공유기 설치해주는게 국룰
        끝에 집은 모름. 함정임
        */
        count = 1;
        temp = x[0];
        for (int i = 1; i < N; ++i) {
            if (x[i] - temp >= mid_distance) {
                count += 1;
                temp = x[i];
            }
        }
        // 가능한지 아닌지 물어보는 부분
        if (count < C) {
            max_distance = mid_distance - 1;
        } else {
            if (mid_distance > answer) {
                answer = mid_distance;
            }
            min_distance = mid_distance + 1;
        }
    }
    cout << answer << endl;
    return 0;
}