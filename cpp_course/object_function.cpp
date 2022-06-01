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
        bool hasHonors() {
            if (gpa >= 3.5) {
                return true;
            }
            return false;
        }

    private:
        string name;
        string major;
        double gpa;
        int age;
};



int main() {
  Student student1("John", "CS", 3.5, 20);
  Student student2("Jane", "CSS", 3.2, 20);
  cout << "Has student1 honors? " << (student1.hasHonors() ? "Yes" : "No, GPA is not suffucient") << endl;
  cout << "Has student2 honors? " << (student2.hasHonors() ? "Yes" : "No, GPA is not sufficient") << endl;

  return 0;
}

