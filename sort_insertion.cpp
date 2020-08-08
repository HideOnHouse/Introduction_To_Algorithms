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
    int temp;
    for (int &i : a) {
        i = intDistribution(generator);
    }
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << "Sorting Start" << endl;
    chrono::system_clock::time_point start = chrono::system_clock::now();
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        for (int j = i; j >= 1; --j) {
            if (a[j] >= a[j - 1]) {
                continue;
            } else {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
    chrono::duration<double> sec = chrono::system_clock::now() - start;
    cout << "Time passed : " << sec.count() << " Seconds" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
