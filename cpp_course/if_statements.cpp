// if statement, how it works
#include <iostream>
using namespace std;

int main(void) {
        
        bool isMale = true;
        bool isTall = true;

        if (isMale && isTall) {
                cout << "You are male and you are tall.";
        }else if(isMale && !isTall) {
                cout << "You are male but not tall.";
        }else if(!isMale && isTall) {
                cout << "You are tall but not male.";
        }else {
                cout << "You are not a male and not tall.";
        }
        return 0;
}