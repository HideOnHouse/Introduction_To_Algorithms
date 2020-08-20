#include <iostream>
#include <vector>

using namespace std;
/*
 * 단순한 재귀 문제
 * 큰 삼각형은 작은 삼각형을 3번 그린다.
 * 삼각형을 그리는 기준은 위쪽 꼭지점을 기준으로 정해 줬다
 * 그려지는 규칙을 잘 보면, 위쪽 꼭지점을 기준으로 아래쪽 두 삼각형의 꼭지점은 size / 2와 관계있다는 것을 알 수 있다
 * 정적 이차원 배열이나 동적 이차원 배열로 풀 수도 있으나, 최종적으로는 깔끔하게 벡터로 작성
 *
 */
void draw(vector<vector<char> > &arr, int top_x, int top_y, int size);

int main() {
    int n;
    cin >> n;
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    vector<vector<char> > arr(n, vector<char>(2 * n - 1, ' '));
    draw(arr, n - 1, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}

void draw(vector<vector<char> > &arr, int top_x, int top_y, int size) {
    if (size == 3) {
        arr[top_y][top_x] = '*';
        arr[top_y][top_x] = '*';
        arr[top_y + 1][top_x - 1] = '*';
        arr[top_y + 1][top_x + 1] = '*';
        arr[top_y + 2][top_x - 2] = '*';
        arr[top_y + 2][top_x - 1] = '*';
        arr[top_y + 2][top_x] = '*';
        arr[top_y + 2][top_x + 1] = '*';
        arr[top_y + 2][top_x + 2] = '*';
    } else {
        int temp = size / 2;
        draw(arr, top_x, top_y, size / 2);
        draw(arr, top_x - temp, top_y + temp, size / 2);
        draw(arr, top_x + temp, top_y + temp, size / 2);
    }
}