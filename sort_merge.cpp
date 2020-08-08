#include <iostream>
#include <random>
#include <chrono>

using namespace std;

#define ARRAY_SIZE 100000

void merge(int *arr, int start, int mid, int end);

void mergeSort(int *arr, int start, int end);

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
    mergeSort(a, 0, ARRAY_SIZE);
    chrono::duration<double> sec = chrono::system_clock::now() - start;
    cout << "Time passed : " << sec.count() << " Seconds" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

void merge(int *arr, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = 0;
    int sorted[end - start + 1];
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i += 1;
        } else {
            sorted[k] = arr[j];
            j += 1;
        }
        k += 1;
    }
    if (i > mid) {
        for (int l = j; l <= end; ++l) {
            sorted[k] = arr[l];
            k += 1;
        }
    } else {
        for (int l = i; l <= mid; ++l) {
            sorted[k] = arr[l];
            k += 1;
        }
    }
    for (int l = start; l <= end; ++l) {
        arr[l] = sorted[l-start];
    }
}

void mergeSort(int *arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}