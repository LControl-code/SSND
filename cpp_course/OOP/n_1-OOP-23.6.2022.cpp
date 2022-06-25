#include <iostream>
// using std::cin;
using std::cout;
using std::endl;
using std::string;

class AbstractEmployee {
  virtual void AskForPromotion()=0; // pure virtual function that is obligatory to be implemented in derived classes
};

class Employee: AbstractEmployee {
private:
  string Company;
  int Age;
protected:
  string Name;
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

  void AskForPromotion() {
    if(Age >= 30) {
      cout << Name << " got promoted" << endl;
    } else {
      cout << Name << ", sorry NO promotion for you" << endl;
    }
  }

  void Work() {
    cout << Name << " is checking email, task backlog, performing tasks..." << endl;
  }
}; // end of class Employee, now we can use Employee in other files


class Developer:public Employee {
  public:
  string FavProgrammingLanguage; // favorite programming
  Developer(string name, string company, int age, string favProgrammingLanguage)
    :Employee(name, company, age){
      FavProgrammingLanguage = favProgrammingLanguage; // the other constructor is calling the base class constructor
    }

  void FixBug() {
    cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
  }

  void Work() {
    cout << Name << " is coding " << FavProgrammingLanguage << " programs" << endl;
  }
};


class Teacher:public Employee {
  private:
  string Subject;
  protected:
  public:

  Teacher(string name, string company, int age, string subject)
    :Employee(name, company, age) { // passing the parameters to the base class constructor
      Subject = subject;
    }

  void PrepareLesson() {
    cout << Name << " is preparing lesson on " << Subject << endl;
  }

  void Work() {
    cout << Name << " is teaching " << Subject << endl;
  }

};

int main() {
  Employee employee1("John", "Google", 30);
  // employee1.Name = "John"; // when we use setters, we don't need to use the dot operator
  // employee1.Company = "Google";
  // employee1.Age = 30;
  employee1.setName("Mery");
  employee1.setAge(13); // this will not work because of the if statement in setAge
  employee1.IntroduceYourself();
  employee1.Print();
  employee1.Work();
  employee1.AskForPromotion();

  cout << "\n\n\n";

  Employee employee2  ("Saldina", "YT-CodeBeaty", 25);
  // employee2.Name = "Saldina";
  // employee2.Company = "YT-CodeBeaty";
  // employee2.Age = 25;
  employee2.IntroduceYourself();
  employee2.Print();
  employee2.Work();
  employee2.AskForPromotion();

  cout << "\n\n\n";

  Employee employee3 = Employee("Jonas", "Facebook", 65);
  employee3.IntroduceYourself();
  employee3.Print();
  employee3.Work();
  employee3.AskForPromotion();


  cout << "\n\n\n";

  Developer developer1("Maria", "Google", 30, "C++");
  developer1.IntroduceYourself();
  developer1.Print();
  developer1.FixBug();
  developer1.Work();
  developer1.AskForPromotion();

  cout << "\n\n\n";

  Teacher teacher1("Mark", "Menza", 55, "Math");
  teacher1.IntroduceYourself();
  teacher1.Print();
  teacher1.PrepareLesson();
  teacher1.Work();
  teacher1.AskForPromotion();

  return 0;
} // ended 1:21:00 out of 1:30:25