#include <iostream>
using namespace std;

// create a class "Student" with these parameters:
// - name
// - major
// - gpa
class Student {
    public:
        Student(string name, string major, double gpa, int age) {
            this->name = name;
            this->major = major;
            this->gpa = gpa;
            this->age = age;
        }
        // create a method
    private:
        string name;
        string major;
        double gpa;
        int age;
};



int main() {

  return 0;
}

