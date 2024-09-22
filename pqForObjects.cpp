#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Student{
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const {
        return this->marks < obj.marks;
    }  
};

struct Compare {
    bool operator() (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;
    }
};

int main(){
    priority_queue<Student> pq;

    priority_queue<pair<string, int>, vector<pair<string, int>>,Compare> pqPair;

    pq.push(Student("Shoruv", 700));
    pq.push(Student("Shahidur", 900));
    pq.push(Student("Rahman", 800));

    pqPair.push(make_pair("Shoruv", 700));
    pqPair.push(make_pair("Shahidur", 900));
    pqPair.push(make_pair("Rahman", 800));

    while(!pqPair.empty()) {
        cout << pqPair.top().first << ", " << pqPair.top().second << endl;
        pqPair.pop();
    }
}