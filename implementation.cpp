#include <iostream>
#include <vector>
using namespace std;

class Heap{
    vector<int> vec;
public:
  void push(int val) {
    vec.push_back(val);

    // fix heap
    int x = vec.size()-1;
    int par = (x-1)/2;

    while (par >= 0 && vec[x] > vec[par]) {
        swap(vec[x],vec[par]);
        x = par;
        par = (x-1)/2;
    }
  }

  void heapify(int i) {

    if(i >= vec.size()) {
        return;
    }

    int l = 2*i+1;
    int r = 2*i+2;
    int maxIdx = i;

    if (l < vec.size() && vec[maxIdx] < vec[l]) {
        maxIdx = l;
    }

    if (r < vec.size() && vec[maxIdx] < vec[r]) {
        maxIdx = r;
    }

    swap(vec[i], vec[maxIdx]);

    if(maxIdx != i) {
        heapify(maxIdx);
    }
  }

  void pop(){
    swap(vec[0], vec[vec.size()-1]);
    vec.pop_back();
    heapify(0);
  }

  int top(){
    return vec[0];
  }

  bool empty(){
    return vec.size() == 0;
  }  
};

int main(){
    Heap heap;
    heap.push(83);
    heap.push(32);
    heap.push(67);
    heap.push(100);

    while (!heap.empty()) {
        cout << heap.top() <<" ";
        heap.pop();
    }
    
}