#include <iostream>
#include <string>
using namespace std;

int main(void) {

        string name = "Janko Hrasko";

        for(int i = 0; i < name.length(); i++){
                cout << name[i];
        }

        name[2] = char(13);
        cout << endl;

        for(int i = name.length() - 1; i >= 0; i--){
                cout << name[i];
        }

        cout << endl;
        getline(cin, name);

        cout << "Cela veta: " << name << endl;

        char z = ' ';

        cin.get(z); // dostava kazdy znak, aj enter
        cout << "Zadali ste znak: " << z; // vypise aj enter
        return 0;
}
