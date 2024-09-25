#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void slidingWindow(vector<int> arr, int k) {
    priority_queue<pair<int, int>> pq;

    for (int i=0; i<k; i++) {
        pq.push(make_pair(arr[i], i));
    }

    cout << "output: " << pq.top().first << endl;

    for (int i=k; i<arr.size(); i++) {
        while (!pq.empty() && pq.top().second <= (i-k)) {
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
        cout << "output: " << pq.top().first << endl;

    }

    cout << endl;
}

int main () {
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    slidingWindow(arr, 3);
}