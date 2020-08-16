#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 백준 7785번
 * 처음에는 해시 테이블이 떠올랐고, 해시함수를 따로 구현하여 해시 테이블을 만들었다 [1000000]
 * 당연히 안됬음
 * 생각해보니 enter은 홀로 존재할 수 있지만, leave는 반드시 짝이 있다는 사실을 깨달음
 * 그럼 나간 사람의 이름은 반드시 짝수번 존재할 것임
 * 그럼 일단 사전 역순으로 정렬하고, 이름이 홀수번 (i 와 i + 1이 다른경우) 일때만 출력하면 될듯
 */

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> str;
    for (int i = 0; i < n; ++i) {
        string name, _;
        cin >> name >> _;
        str.push_back(name);
    }

    sort(str.rbegin(), str.rend());
    for (auto i = str.begin(); i != str.end(); ++i) {
        if (*i == *(i + 1)) {
            ++i;
        } else {
            cout << *i << '\n';
        }
    }
    return 0;
}
