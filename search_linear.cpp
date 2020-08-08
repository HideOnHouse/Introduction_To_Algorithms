#include <iostream>
#include <random>
#include <chrono>

using namespace std;

#define ARRAY_SIZE 100000
int main() {
    random_device randomDevice;
    mt19937_64 generator(randomDevice());
    uniform_int_distribution<int> intDistribution(0, ARRAY_SIZE);
    int a[ARRAY_SIZE];
    int target;
    bool flag = true;
    for (int &i : a) {
        i = intDistribution(generator);
    }
    cout << "Please input target\n>>>";
    cin >> target;
    cout << "Linear Search Start" << endl;
    chrono::system_clock::time_point start = chrono::system_clock::now();
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (a[i] == target) {
            cout << "Index is : " << i << endl;
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Index is : NIL" << endl;
    }
    chrono::duration<double> sec = chrono::system_clock::now() - start;
    cout << "Time passed : " << sec.count() << " Seconds" << endl;
    return 0;
}
