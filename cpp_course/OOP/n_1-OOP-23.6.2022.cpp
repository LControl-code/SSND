#include <iostream>
// using std::cin;
using std::cout;
using std::endl;
using std::string;

class Employee {
private:
  string Name;
  string Company;
  int Age;
public:
  Employee(string name, string company, int age) {
    Name = name;
    Company = company;
    Age = age;
  }

  void setName(string name) {
    Name = name;
  }
  string getName(){
    return Name;
  }

  void setCompany(string company) {
    Company = company;
  }
  string getCompany(){
    return Company;
  }

  void setAge(int age) {
    if(age >= 18)
      Age = age;
  }
  int getAge(){
    return Age;
  }

  void IntroduceYourself() {
    cout << "Hello, my name is " << Name << " and I work at " << Company << endl;
    cout << "I'm " << Age << " years old" << endl;
  }

  void Print() {
    cout << "Name: " << Name << endl;
    cout << "Company: " << Company << endl;
    cout << "Age: " << Age << endl;
  }

}; // end of class Employee, now we can use Employee in other files

int main() {
  Employee employee1("John", "Google", 30);
  // employee1.Name = "John";
  // employee1.Company = "Google";
  // employee1.Age = 30;
  employee1.setName("Mery");
  employee1.setAge(13); // this will not work because of the if statement in setAge
  employee1.IntroduceYourself();
  employee1.Print();

  Employee employee2  ("Saldina", "YT-CodeBeaty", 25);
  // employee2.Name = "Saldina";
  // employee2.Company = "YT-CodeBeaty";
  // employee2.Age = 25; 
  employee2.IntroduceYourself();
  employee2.Print();

  Employee employee3 = Employee("Jonas", "Facebook", 65);
  employee3.Print();
  return 0;
} // ended 43:50 out of 1:30:25