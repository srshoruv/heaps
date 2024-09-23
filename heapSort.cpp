#include <iostream>
#include <vector>
using namespace std;

void heapify(int i, vector<int> &arr, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxIdx = i;

    if(left < n && arr[left] > arr[maxIdx]) {
        maxIdx = left;
    }

    if(right < n && arr[right] > arr[maxIdx]) {
        maxIdx = right;
    }

    if(maxIdx != i) {
        swap(arr[i], arr[maxIdx]);
        heapify(maxIdx, arr, n);
    }
}

void heapSort (vector<int> &arr) {
    int n = arr.size();

    for (int i = n/2-1; i>=0; i--) {
        heapify(i, arr, n);
    }

    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main() {
    vector<int> arr = {5,2,1,4,3};
    heapSort(arr);
    
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}