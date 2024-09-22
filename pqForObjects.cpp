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

int main(){
    priority_queue<Student> pq;

    pq.push(Student("Shoruv", 700));
    pq.push(Student("Shahidur", 900));
    pq.push(Student("Rahman", 800));

    while(!pq.empty()) {
        cout << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }
}