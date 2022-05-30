// inicialization of a function
#include <iostream>
using namespace std;

// referencing the function (prototype)
string sayHi(string _name);

int main(void) {

        string name;
        cin >> name;
        string mood = sayHi(name);

        cout << "\n you are " << mood;
        return EXIT_SUCCESS;
}

string sayHi(string _name) {
        cout << "Hello " << _name << endl;

        cout << "How are you?";

        string mood;
        cin >> mood;

        return mood;
}