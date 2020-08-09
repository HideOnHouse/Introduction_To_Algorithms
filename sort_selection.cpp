#include <iostream>
#include <random>
#include <chrono>

using namespace std;

#define ARRAY_SIZE 100000

void swap(int &a, int &b);

int main() {
    random_device randomDevice;
    mt19937_64 generator(randomDevice());
    uniform_int_distribution<int> intDistribution(0, ARRAY_SIZE);
    int a[ARRAY_SIZE];
    int min;
    for (int &i : a) {
        i = intDistribution(generator);
    }
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << "Sorting Start" << endl;
    chrono::system_clock::time_point start = chrono::system_clock::now();
    for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
        min = i;
        for (int j = i; j < ARRAY_SIZE; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
    chrono::duration<double> sec = chrono::system_clock::now() - start;
    cout << "Time passed : " << sec.count() << " Seconds" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}