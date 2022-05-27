#include <iostream>
using namespace std;

// int Sucet(int a, int b) {
//         return a+b;
// }

// int SucinScitanim(int a, int b) {
//         long sucin = 0;
//         if(b>=0) {
//                 while(b--)
//                         sucin += a;
//         } else {
//                 while(b++)
//                         sucin -= a;
//         }
//         return sucin;
// }

// int main() {

//         int num1, num2;
//         cin >> num1 >> num2;

//         printf("Sucet cisel %i a %i", num1, num2);
//         cout << Sucet(num1, num2) << endl;
//         cout << Sucet(num1+15, num2-5) << endl;
//         cout << Sucet(num1*5, num2++) << endl;
//         cout << Sucet(num1*6, num2--) << endl;
//         cout << SucinScitanim(num1, num2) << endl;

//         return EXIT_SUCCESS;
// }

void Cls(void) {
        system("echo clear");
}

void KresliStvorec(int r, bool zmazat) {
        if (zmazat) Cls();
        for (int i =0; i<r;i++){
                for (int j = 0; j < r; j++)
                        cout << "* ";
                cout << endl;
        }
}

int main() {
        int r = 0;
        bool zmazat = false;
        cin >> r;
        while(r) {
                
                KresliStvorec(r, true);
                cout << endl << endl;
                cin >> r;
        }
        return EXIT_SUCCESS;
}