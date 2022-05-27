#include <iostream>
using namespace std;

int main() {

        int null_int = '\0'; // \0 is a null character that doesn't hold any value
        
        if (null_int == '\0' ){
                cout << "I don't have any value inside me.\nWell...I have, it's (" << null_int << ") and i think that's beautiful.";
        }
        int age = 19;
        int *pAge = &age;

        return 0;
}