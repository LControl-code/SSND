#include <iostream>
using namespace std;

int main(){

        int age = 19;
        int *pAge = &age;

        cout << "The value of variable: " << age << endl;
        cout << "The adress of a variable: " << &age << endl;
        cout << "The value of a pointer: " << pAge << " (that is referencing to variable age)" << endl;
        cout << "The deferenced value of a pointer: " << *pAge << endl;

        // mailbox is the & and the content of it is *
        // pointer is just a new datatype that's typed like this ->     data type       *var_name       =       &var_adress_to_point
        //                                                                                               (int, string, ...)
        return 0;
}